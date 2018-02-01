#ifndef LC4500_DRIVER_COMMANDS_H
#define LC4500_DRIVER_COMMANDS_H

#include "common.h"
#include "error.h"
#include "packager.h"

#define PEM_CMD_VERSION_STR_LEN     32
#define PEM_CMD_SOLUTION_NAME_LEN   32

#define    ONE_BPP_PTN_SIZE        52046
#define    TWO_BPP_PTN_SIZE        208006
#define    THREE_BPP_PTN_SIZE        208022
#define    FOUR_BPP_PTN_SIZE        208054
#define    FIVE_BPP_PTN_SIZE        416054
#define    SIX_BPP_PTN_SIZE        416182
#define    SEVEN_BPP_PTN_SIZE        416438
#define    EIGHT_BPP_PTN_SIZE        416950

class Commands
{
public:

    Commands();

    typedef enum
    {
    VER_PEM = 0x00,
    VER_DLPC350 = 0x11,
    VER_DLPC350_API = 0x12,
    VER_DLPC350_SW = 0x13,
    VER_DLPC350_SEQ = 0x14,
    VER_MANUFACTURER = 0x30,
    VER_MODEL_NUM = 0x40,
    VER_SERIAL_NUM = 0x50,
    VER_LED_TEMP = 0x70
    } PEM_Version_t;

    typedef enum
    {
    SEQ_MANUAL,
    SEQ_AUTO,
    } PEM_LEDSequence_t;

    typedef enum
    {
    TEST_PTN_SOLID_FIELD = 0x00,
    TEST_PTN_HORIZ_RAMP = 0x01,
    TEST_PTN_VERT_RAMP = 0x02,
    TEST_PTN_HORIZ_LINES = 0x03,
    TEST_PTN_DIAG_LINES = 0x04,
    TEST_PTN_VERT_LINES = 0x05,
    TEST_PTN_GRID = 0x06,
    TEST_PTN_CHECKS = 0x07,
    TEST_PTN_RGB_RAMP = 0x08,
    TEST_PTN_COLOR_BARS = 0x09,
    TEST_PTN_STEP_BARS = 0x10
    } PEM_TestPattern_t;

    typedef struct
    {
    uint8 Rotate;
    uint8 LongAxisFlip;
    uint8 ShortAxisFlip;
    uint8 Reserved[11];
    } PEM_DisplaySetting_t;

    typedef enum
    {
    PWR_STANDBY = 0x00,
    PWR_NORMAL = 0x01,
    } PEM_PowerMode_t;

    typedef struct
    {
    PEM_LEDSequence_t SequenceControl;
    uint8 RedEnable;
    uint8 GreenEnable;
    uint8 BlueEnable;
    uint16 Red;
    uint16 Green;
    uint16 Blue;
    } PEM_LEDCurrent_t;

    typedef enum
    {
    DISP_MODE_STATIC_IMAGE = 0x00,
    DISP_MODE_TEST_PATTERN = 0x01,
    DISP_MODE_HDMI_VIDEO = 0x02,
    DISP_MODE_STREAM_PATTERN = 0x04,
    DISP_MODE_FLASH_IMAGE = 0x05,
    } PEM_DisplayMode_t;

    ErrorCode_t PEM_CMD_SetLEDCurrent(PEM_LEDCurrent_t *LEDSetting);

    ErrorCode_t PEM_CMD_GetLEDCurrent(PEM_LEDCurrent_t *LEDSetting);

    ErrorCode_t PEM_CMD_SetDisplayMode(PEM_DisplayMode_t mode);

    ErrorCode_t PEM_CMD_SetTestPattern(PEM_TestPattern_t pattern);

/*Get software and firmware versions*/
    ErrorCode_t PEM_CMD_GetVersion(PEM_Version_t versionType, char *versionStr);

    ErrorCode_t PEM_CMD_DisplayStaticImage(char const *fileNameWithPath);

    ErrorCode_t PEM_CMD_SoftReset(void);


    ErrorCode_t PEM_CMD_GetDisplayMode(PEM_DisplayMode_t *displayMode);

/*Open / Close connection to device*/
    ErrorCode_t PEM_CMD_Open(void);

    ErrorCode_t PEM_CMD_Close(void);

private:
    Packager packager;

    ErrorCode_t PEM_CMD_GetTestPattern(PEM_TestPattern_t *testPattern);

    ErrorCode_t PEM_CMD_DisplayStaticColor(uint32 color);

    ErrorCode_t PEM_CMD_GetDisplaySetting(PEM_DisplaySetting_t *setting);

    ErrorCode_t PEM_CMD_SetDisplaySetting(PEM_DisplaySetting_t *setting);

    ErrorCode_t PEM_CMD_LoadArrayImage(uint8 *arrayIndex, char const *fileNameWithPath);

    ErrorCode_t PEM_CMD_DisplayArrayImage(uint8 *arrayIndex);

    ErrorCode_t PEM_CMD_ApplyNonUniformityCorrection(uint8 *arrayIndex);

    ErrorCode_t PEM_CMD_LoadNonUniformityArrayImage(uint8 *arrayIndex, char const *fileNameWithPath);

    ErrorCode_t PEM_CMD_GetPowerMode(PEM_PowerMode_t *powerMode);

    ErrorCode_t PEM_CMD_SetPowerMode(PEM_PowerMode_t powerMode);

    ErrorCode_t PEM_CMD_ShutDown(void);

    ErrorCode_t PEM_CMD_HardReset(void);

};

#endif //LC4500_EXPERIMENTAL_COMMANDS_H
