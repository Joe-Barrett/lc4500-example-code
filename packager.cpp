#include <unistd.h>
#include "common.h"
#include "packager.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "ClangTidyInspection"
static uint8 packetBuffer[HEADER_SIZE + MAX_PACKET_SIZE + CHECKSUM_SIZE];
static uint8 *const packetData = packetBuffer + HEADER_SIZE;
static Packager::PEM_PacketType_t PEM_PacketType;
static uint8 contFlag;
static uint8 recvFlag;
static uint16 commandId;
static uint16 dataLength;
static uint16 parseIndex;
static int PEM_PKT_Socket;


Packager::Packager() = default;

ErrorCode_t Packager::PEM_CMD_PKT_ConnectToPEM()
{
    PEM_PKT_Socket = tcpClient.TCP_Connect((char *) PEM_IP, PEM_PORT);
    if (PEM_PKT_Socket < 0)
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Packager::PEM_CMD_PKT_DisconnectPEM()
{
    tcpClient.TCP_Disconnect(PEM_PKT_Socket);
    return SUCCESS;
}

/* Packet Creation */

ErrorCode_t Packager::PEM_CMD_PKT_CommandInit(PEM_CommandType_t cmdType, uint16 cmdId)
{
    if (cmdType == CMD_PKT_TYPE_WRITE)
    {
        PEM_PacketType = PKT_TYPE_WRITE;
    }
    else if (cmdType == CMD_PKT_TYPE_READ)
    {
        PEM_PacketType = PKT_TYPE_READ;
    }
    else
    {
        return FAIL;
    }

    contFlag = 0;
    commandId = cmdId;
    dataLength = 0;
    return SUCCESS;
}

int Packager::PEM_CMD_PKT_PutData(uint8 *data, unsigned long int size)
{
    if (data == nullptr)
    {
        return -1;
    }

    while (size != 0u)
    {
        auto copySize = static_cast<int>(size);
        if (dataLength == MAX_PACKET_SIZE)
        {
            if (PEM_CMD_PKT_SendPacket(1) != 0)
            {
                return 1;
            }
            dataLength = 0;
        }

        if (dataLength + copySize > MAX_PACKET_SIZE)
        {
            copySize = MAX_PACKET_SIZE - dataLength;
        }

        memcpy(packetData + dataLength, data, static_cast<size_t>(copySize));
        dataLength += copySize;
        size -= copySize;
    }

    return 0;
}

int Packager::PEM_CMD_PKT_PutInt(uint32 value, unsigned int size)
{
    uint8 data[4];
    unsigned int i;

    if (size > 4)
    {
        return -1;
    }

    for (i = 0; i < size; i++)
    {
        data[i] = (uint8) (value & 0xFF);
        value >>= 8;
    }

    if (PEM_CMD_PKT_PutData(data, size) != 0)
    {
        return -1;
    }
    return 0;
}

int Packager::PEM_CMD_PKT_PutFile(char const *fileName)
{
    int error = 0;
    FILE *fp;
    int copySize;

    fp = fopen(fileName, "rb");
    if (fp == nullptr)
    {
        return -1;
    }

    while (!feof(fp))
    {
        if (dataLength == MAX_PACKET_SIZE)
        {
            if (PEM_CMD_PKT_SendPacket(1) != 0)
            {
                error = -1;
                break;
            }
        }

        copySize = MAX_PACKET_SIZE - dataLength;
        copySize = static_cast<int>(fread(packetData + dataLength, 1, static_cast<size_t>(copySize), fp));
        if (copySize <= 0)
        {
            break;
        }
        dataLength += copySize;
    }
    fclose(fp);
    return error;

}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"

int Packager::PEM_CMD_PKT_GetFile(char const *fileName, uint32 size)
{
    FILE *fp;
    int result = 0;
    uint32 remainingSize = size;

    if (packetBuffer[0] != PKT_TYPE_READ_RESP)
    {
        return -1;
    }

    fp = fopen(fileName, "wb");
    if (fp == nullptr)
    {
        return -1;
    }

    if (remainingSize == 0)
    {
        remainingSize = MAX_PACKET_SIZE;
    }

    while (remainingSize != 0u)
    {
        unsigned int copySize = dataLength - parseIndex;
        if (copySize == 0)
        {
            if (PEM_CMD_PKT_ReceivePacket(0) != 0)
            {
                if (size != 0)
                {
                    result = -1;
                }
                break;
            }

            copySize = dataLength - parseIndex;
        }

        if (copySize >= remainingSize)
        {
            copySize = remainingSize;
        }

        if (fwrite(packetData + parseIndex, 1, copySize, fp) != copySize)
        {
            result = -1;
            break;
        }

        parseIndex += copySize;

        if (size != 0)
        {
            remainingSize -= copySize;
        }
    }
    fclose(fp);
    return result;
}

#pragma clang diagnostic pop

int Packager::PEM_CMD_PKT_GetData(uint8 *data, unsigned long int size)
{
    if (packetBuffer[0] != PKT_TYPE_READ_RESP)
    {
        return -1;
    }

    while (size != 0u)
    {
        unsigned int copySize = dataLength - parseIndex;
        if (copySize == 0)
        {
            if (PEM_CMD_PKT_ReceivePacket(0) != 0)
            {
                return -1;
            }
            copySize = dataLength - parseIndex;
        }

        if (copySize >= size)
        {
            copySize = static_cast<unsigned int>(size);
        }

        memcpy(data, packetData + parseIndex, copySize);
        parseIndex += copySize;
        size -= copySize;
        data += copySize;
    }
    return 0;
}

uint32 Packager::PEM_CMD_PKT_GetInt(unsigned int size)
{
    uint32 value = 0;
    uint8 data[4];
    unsigned int i;

    if (size > 4)
    {
        return 0;
    }

    if (PEM_CMD_PKT_GetData(data, size) != 0)
    {
        return 0;
    }

    for (i = 0; i < size; i++)
    {
        value |= data[i] << (i * 8);
    }
    return value;
}

uint8 Packager::PEM_CMD_PKT_CalcChecksum()
{
    int i;
    int sum = 0;
    for (i = 0; i < dataLength + HEADER_SIZE; i++)
    {
        sum += packetBuffer[i];
    }
    return (uint8) (sum & 0xFF);
}

int Packager::PEM_CMD_PKT_ReceivePacket(BOOL firstPkt)
{
    unsigned long int mask;
    int i;

    dataLength = 0;
    parseIndex = 0;

    if (firstPkt == 0)
    {
        if (recvFlag == 0 || recvFlag == 3)
        {
            return -1;
        }
    }

    // Read Header
    if (tcpClient.TCP_Receive(PEM_PKT_Socket, packetBuffer, HEADER_SIZE) != 0)
    {
        return -1;
    }


    dataLength = packetBuffer[4] | packetBuffer[5] << 8;
    // Read data
    if (tcpClient.TCP_Receive(PEM_PKT_Socket, packetData, dataLength + 1) != 0)
    {
        return -1;
    }

    /*PRINT SECTION*/
    /*printf("                 Type\tCMD1\tCMD2\tFlags\tLN1\tLN2\t");
    if (dataLength > 0)
    {
        printf("Data");
    }
    for (int k = 0; k < dataLength; ++k)
    {
        printf("\t");
    }
    printf("Checksum\n");
    printf("RECEIVED PACKET: ");
    for (int j = 0; j < HEADER_SIZE + dataLength + 1; ++j)
    {
        printf("%d\t", packetBuffer[j]);
    }
    printf("\n");*/
    /*FINSIH PRINT SECTION*/

    if (packetData[dataLength] != PEM_CMD_PKT_CalcChecksum())
    {
        printf("ERROR: Checksum failed in the command's response packet\n");
        return -1;
    }

    if (packetBuffer[0] != PEM_PacketType + 1)
    {
        switch (packetBuffer[0])
        {
            case 0x00:
                printf("INFO: Command not executed. Device is busy\n");
                break;

            case 0x01:
                printf("INFO: Command packet contains error\n");

                mask = 0;
                i = 0;
                while (dataLength--)
                {
                    if (packetBuffer[(6 + i)] != 0)
                    {
                        mask |= (1 << (packetBuffer[(6 + i)] - 1));
                    }
                    i++;
                }

                if ((mask & ERR_UNKNOWN) == ERR_UNKNOWN)
                {
                    printf("COMMAND PACKET ERROR: Execution failed with unknown error\n");
                }
                else if ((mask & ERR_INVALID_COMMAND) == ERR_INVALID_COMMAND)
                {
                    printf("COMMAND PACKET ERROR: Invalid command\n");
                }
                else if ((mask & ERR_INVALID_PARAMETER) == ERR_INVALID_PARAMETER)
                {
                    printf("COMMAND PACKET ERROR: Invalid parameter\n");
                }
                else if ((mask & ERR_OUT_OF_RESOURCE) == ERR_OUT_OF_RESOURCE)
                {
                    printf("COMMAND PACKET ERROR: Out of resource\n");
                }
                else if ((mask & ERR_HARDWARE_FAILURE) == ERR_HARDWARE_FAILURE)
                {
                    printf("COMMAND PACKET ERROR: Hardware failure\n");
                }
                else if ((mask & ERR_HARDWARE_BUSY) == ERR_HARDWARE_BUSY)
                {
                    printf("COMMAND PACKET ERROR: Hardware busy\n");
                }
                else if ((mask & ERR_NOT_INITIALIZED) == ERR_NOT_INITIALIZED)
                {
                    printf("COMMAND PACKET ERROR: Not initialized\n");
                }
                else if ((mask & ERR_OBJECT_NOT_FOUND) == ERR_OBJECT_NOT_FOUND)
                {
                    printf("COMMAND PACKET ERROR: Object not found\n");
                }
                else if ((mask & ERR_CHECKSUM_ERR) == ERR_CHECKSUM_ERR)
                {
                    printf("COMMAND PACKET ERROR: Checksum error\n");
                }
                else if ((mask & ERR_PACKET_FORMAT) == ERR_PACKET_FORMAT)
                {
                    printf("COMMAND PACKET ERROR: Unexpected payload size\n");
                }
                else if ((mask & ERR_INCORRECT_CONTINUATION) == ERR_INCORRECT_CONTINUATION)
                {
                    printf("COMMAND PACKET ERROR: Incorrect continuation flag\n");
                }
                else
                {
                    printf("COMMAND PACKEt ERROR: Undocumented error\n");
                }

                break;

            case 0x02:
            case 0x04:
                printf("COMMAND PACKET ERROR: returned command type as Write = [0x02] or Read = [0x04] command!!!\n");
                break;
            default:
                printf("ERROR: Unknown packet type\n");
                break;
        }
        return -1;
    }

    recvFlag = packetBuffer[3];
    if (firstPkt != (recvFlag == 0 || recvFlag == 1))
    {
        return -1;
    }

    if (recvFlag == 3)
    {
        printf("COMMAND SUCCESS!");
        /*Command success*/
    }
    return 0;
}

int Packager::PEM_CMD_PKT_SendPacket(BOOL more)
{
    uint8 flag;
    packetBuffer[0] = PEM_PacketType;
    packetBuffer[1] = (uint8) ((commandId >> 8) & 0xFF);
    packetBuffer[2] = (uint8) ((commandId) & 0xFF);

    if (contFlag)
    {
        if (more)
        {
            flag = 2;
        }
        else
        {
            flag = 3;
        }
    }
    else
    {
        if (more)
        {
            flag = 1;
        }
        else
        { flag = 0; }
    }
    contFlag = (uint8) more;

    packetBuffer[3] = flag;
    packetBuffer[4] = (uint8) (dataLength & 0xFF);
    packetBuffer[5] = (uint8) ((dataLength >> 8) & 0xFF);
    packetData[dataLength] = PEM_CMD_PKT_CalcChecksum();

    int length = dataLength + HEADER_SIZE + CHECKSUM_SIZE;

    /*PRINT SECTION*/
    /*printf("            \tType\tCMD1\tCMD2\tFlags\tLN1\tLN2\t");
    if (dataLength > 0)
    {
        printf("Data");
    }
    int printLength = (dataLength < 20) ? dataLength : 20;
    for (int k = 0; k < printLength; ++k)
    {
        printf("\t");
    }
    printf("Checksum\n");
    printf("SENT PACKET:\t");
    for (int j = 0; j < HEADER_SIZE + printLength + 1; ++j)
    {
        printf("%d\t", packetBuffer[j]);
    }
    printf("\n");*/
    /*END PRINT SECTION*/

    if (tcpClient.TCP_Send(PEM_PKT_Socket, packetBuffer, length))
    {
        return -1;
    }
    if (PEM_CMD_PKT_ReceivePacket(1))
    {
        return -1;
    }

    if (more == 0 && recvFlag == 0)
    {
        printf("PACKET SENT\n");
    }
    return 0;
}

int Packager::PEM_CMD_PKT_SendCommand(void)
{
    return PEM_CMD_PKT_SendPacket(0);
}

#pragma clang diagnostic pop