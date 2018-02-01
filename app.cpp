#include <unistd.h>
#include "common.h"
#include "error.h"
#include "commands.h"
#include "packager.h"

Commands commands;

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

void enableLED(){
    Commands::PEM_LEDCurrent_t newCurrent;
    newCurrent.SequenceControl = Commands::SEQ_AUTO;
    newCurrent.RedEnable       = 0;
    newCurrent.GreenEnable     = 0;
    newCurrent.BlueEnable      = 0;
    newCurrent.Red             = 100;
    newCurrent.Green           = 100;
    newCurrent.Blue            = 100;
    if (commands.PEM_CMD_SetLEDCurrent(&newCurrent))
    {
        printf("Couldn't set currents\n");
    }
}

void getLED()
{
    printf("Getting current LED currents\n");
    Commands::PEM_LEDCurrent_t currentSettings;

    if (commands.PEM_CMD_GetLEDCurrent(&currentSettings))
    {
        printf("Couldn't read LED Settings\n");
    }
    else
    {
        printf("Current LED Settings Red = %d\tGreen = %d\tBlue = %d\t\n", currentSettings.Red, currentSettings.Green,
               currentSettings.Blue);
    }
}

void cycleTestImages()
{
    printf("Cycling test images\n");
    printf("Setting image mode to test image\n");
    commands.PEM_CMD_SetDisplayMode(Commands::DISP_MODE_TEST_PATTERN);
    commands.PEM_CMD_SetTestPattern(Commands::TEST_PTN_HORIZ_RAMP);
    sleep((unsigned int) (3000 / 1000.0));
    commands.PEM_CMD_SetTestPattern(Commands::TEST_PTN_CHECKS);
}

void getVersion()
{
    char verName[PEM_CMD_VERSION_STR_LEN];
    printf("Getting version\n");
    commands.PEM_CMD_GetVersion(Commands::VER_PEM, &verName[0]);
    printf("PEM Version: %s\n", verName);
    commands.PEM_CMD_GetVersion(Commands::VER_MANUFACTURER, &verName[0]);
    printf("Manufacturer: %s\n", verName);
    commands.PEM_CMD_GetVersion(Commands::VER_MODEL_NUM, &verName[0]);
    printf("Model Number: %s\n", verName);
}

void showImage(char const *filePath)
{
    commands.PEM_CMD_SetDisplayMode(Commands::DISP_MODE_STATIC_IMAGE);
    commands.PEM_CMD_DisplayStaticImage(filePath);
}

void testPower()
{
    printf("SOFT RESET\n");
    commands.PEM_CMD_SoftReset();
}

void getDisplayMode(){
    printf("Getting display mode\n");
    Commands::PEM_DisplayMode_t dMode;
    commands.PEM_CMD_GetDisplayMode(&dMode);
    printf("Display mode is %u\n", dMode);
}

void setDisplayMode(Commands::PEM_DisplayMode_t mode){
    printf("Setting display mode\n");
    commands.PEM_CMD_SetDisplayMode(mode);
}

int main(int argc, char *argv[])
{
    printf("Connecting to device\n");
    if (commands.PEM_CMD_Open())
    {
        printf("Unable to connect\n");
        return -1;
    }
    Packager packager;
    packager.PEM_CMD_PKT_ReceivePacket(0);
    printf("Connection successful\n");
    setDisplayMode(Commands::DISP_MODE_TEST_PATTERN);
    getDisplayMode();
    setDisplayMode(Commands::DISP_MODE_STATIC_IMAGE);
    getDisplayMode();
    showImage("./test_image.bmp");
    sleep((unsigned int) (3000 / 1000.0));
    cycleTestImages();
    printf("Closing connection\n");
    commands.PEM_CMD_Close();
}