#include "common.h"
#include "error.h"
#include "packager.h"
#include "commands.h"

Commands::Commands()
{
}

ErrorCode_t Commands::PEM_CMD_Open(void) {
    return packager.PEM_CMD_PKT_ConnectToPEM();
}

ErrorCode_t Commands::PEM_CMD_Close(void) {
    packager.PEM_CMD_PKT_DisconnectPEM();
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_GetVersion(PEM_Version_t versionType, char *versionStr) {
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_READ, 0x0100);
    if (versionType < VER_PEM && versionType > VER_LED_TEMP) {
        return FAIL;
    }
    packager.PEM_CMD_PKT_PutInt(versionType, 1);
    if (packager.PEM_CMD_PKT_SendCommand()) {
        return FAIL;
    }
    packager.PEM_CMD_PKT_GetData((uint8 *) versionStr, PEM_CMD_VERSION_STR_LEN);
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_SetLEDCurrent(PEM_LEDCurrent_t *LEDSetting)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0104);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->SequenceControl, 1);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->RedEnable, 1);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->GreenEnable, 1);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->BlueEnable, 1);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->Red, 2);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->Green, 2);
    packager.PEM_CMD_PKT_PutInt(LEDSetting->Blue, 2);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_GetLEDCurrent(PEM_LEDCurrent_t *LEDSetting)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_READ, 0x0104);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    LEDSetting->SequenceControl = (PEM_LEDSequence_t) packager.PEM_CMD_PKT_GetInt(1);
    LEDSetting->RedEnable = (uint8) packager.PEM_CMD_PKT_GetInt(1);
    LEDSetting->GreenEnable = (uint8) packager.PEM_CMD_PKT_GetInt(1);
    LEDSetting->BlueEnable = (uint8) packager.PEM_CMD_PKT_GetInt(1);
    LEDSetting->Red = (uint16) packager.PEM_CMD_PKT_GetInt(2);
    LEDSetting->Green = (uint16) packager.PEM_CMD_PKT_GetInt(2);
    LEDSetting->Blue = (uint16) packager.PEM_CMD_PKT_GetInt(2);
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_GetDisplayMode(PEM_DisplayMode_t *displayMode)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_READ, 0x0101);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    *displayMode = (PEM_DisplayMode_t) packager.PEM_CMD_PKT_GetInt(1);
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_SetDisplayMode(PEM_DisplayMode_t mode)
{
    if (mode > DISP_MODE_FLASH_IMAGE)
    {
        return FAIL;
    }
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0101);
    packager.PEM_CMD_PKT_PutInt(mode, 1);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_GetTestPattern(PEM_TestPattern_t *testPattern)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_READ, 0x0103);
    if (packager.PEM_CMD_PKT_SendCommand()){
        return FAIL;
    }
    packager.PEM_CMD_PKT_GetData((uint8 *) &testPattern, 1);
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_SetTestPattern(PEM_TestPattern_t pattern)
{
    if (pattern > TEST_PTN_STEP_BARS)
    {
        return FAIL;
    }
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0103);
    packager.PEM_CMD_PKT_PutInt(pattern, 1);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }

    return SUCCESS;

}

ErrorCode_t Commands::PEM_CMD_DisplayStaticImage(char const *fileNameWithPath)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0105);
    packager.PEM_CMD_PKT_PutFile(fileNameWithPath);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_GetPowerMode(PEM_PowerMode_t *powerMode)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_READ, 0x0330);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    packager.PEM_CMD_PKT_GetData((uint8 *) &powerMode, 1);
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_SetPowerMode(PEM_PowerMode_t powerMode)
{
    if (powerMode > PWR_NORMAL)
    {
        return FAIL;
    }
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0330);
    packager.PEM_CMD_PKT_PutInt((uint32) powerMode, 1);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_ShutDown(void)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0x0331);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_SoftReset(void)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0xFF80);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_HardReset(void)
{
    packager.PEM_CMD_PKT_CommandInit(Packager::CMD_PKT_TYPE_WRITE, 0xFF81);
    if (packager.PEM_CMD_PKT_SendCommand())
    {
        return FAIL;
    }
    return SUCCESS;
}

ErrorCode_t Commands::PEM_CMD_DisplayStaticColor(uint32 color)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_GetDisplaySetting(Commands::PEM_DisplaySetting_t *setting)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_SetDisplaySetting(Commands::PEM_DisplaySetting_t *setting)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_LoadArrayImage(uint8 *arrayIndex, char const *fileNameWithPath)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_DisplayArrayImage(uint8 *arrayIndex)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_ApplyNonUniformityCorrection(uint8 *arrayIndex)
{
    return ERR_HARDWARE_FAILURE;
}

ErrorCode_t Commands::PEM_CMD_LoadNonUniformityArrayImage(uint8 *arrayIndex, char const *fileNameWithPath)
{
    return ERR_HARDWARE_FAILURE;
}
