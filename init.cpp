#include <unistd.h>
#include "common.h"
#include "error.h"
#include "commands.h"
#include "packager.h"

Commands commands;
Packager packager;

void disableLED(){
    Commands::PEM_LEDCurrent_t newCurrent;
    newCurrent.SequenceControl = Commands::SEQ_AUTO;
    newCurrent.RedEnable = 0;
    newCurrent.GreenEnable = 0;
    newCurrent.BlueEnable = 0;
    newCurrent.Red = 0;
    newCurrent.Green = 0;
    newCurrent.Blue = 0;
    if (commands.PEM_CMD_SetLEDCurrent(&newCurrent))
    {
        printf("Couldn't set currents\n");
    }
}

int main(int argc, char *argv[])
{
    printf("Connecting to device\n");
    if (commands.PEM_CMD_Open())
    {
        printf("Unable to connect\n");
        return -1;
    }
    packager.PEM_CMD_PKT_ReceivePacket(0);
    printf("Connection successful\n");
    disableLED();
}