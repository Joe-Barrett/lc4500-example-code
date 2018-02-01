#ifndef LC4500_DRIVER_PACKAGER_H
#define LC4500_DRIVER_PACKAGER_H

#include "error.h"
#include "common.h"
#include "tcp_client.h"

#define HEADER_SIZE     6
#define MAX_PACKET_SIZE 0xFFFF
#define CHECKSUM_SIZE   1

#define PEM_IP   "lc4500-pem.roe.ac.uk"
#define PEM_PORT 0x5555

class Packager
{

public:

    Packager();

    typedef enum
    {
    PKT_TYPE_BUSY       = 0x00,
    PKT_TYPE_ERROR      = 0x01,
    PKT_TYPE_WRITE      = 0x02,
    PKT_TYPE_WRITE_RESP = 0x03,
    PKT_TYPE_READ       = 0x04,
    PKT_TYPE_READ_RESP  = 0x05
    } PEM_PacketType_t;

    typedef enum
    {
    CMD_PKT_TYPE_READ  = 0x00,
    CMD_PKT_TYPE_WRITE = 0x01,
    } PEM_CommandType_t;

    ErrorCode_t PEM_CMD_PKT_ConnectToPEM(void);

    ErrorCode_t PEM_CMD_PKT_DisconnectPEM(void);

    ErrorCode_t PEM_CMD_PKT_CommandInit(PEM_CommandType_t cmdType, uint16 cmdId);

    int PEM_CMD_PKT_PutData(uint8 *data, unsigned long int size);

    int PEM_CMD_PKT_PutInt(uint32 value, unsigned int size);

    int PEM_CMD_PKT_GetData(uint8 *data, unsigned long int size);

    uint32 PEM_CMD_PKT_GetInt(unsigned int size);

    int PEM_CMD_PKT_PutFile(char const *fileName);

    int PEM_CMD_PKT_GetFile(char const *fileName, uint32 size);

    static uint8 PEM_CMD_PKT_CalcChecksum(void);

    int PEM_CMD_PKT_SendCommand(void);

    int PEM_CMD_PKT_ReceivePacket(BOOL firstPkt);

    int PEM_CMD_PKT_SendPacket(BOOL more);

private:
    TcpClient tcpClient;

protected:

};

#endif //LC4500_EXPERIMENTAL_PACKAGER_H
