#ifndef __PWM_MODE_H__
#define __PWM_MODE_H__

    // [DDD-PWM-1]
    // TODO : Developer can setup the PWM mode.

#define DEBUG_MESSAGE   1

typedef enum _PWM_CHANNEL PWM_CHANNEL_ADDRESS;
enum _PWM_CHANNEL
{
    PWM_CHANNEL_OC0A       =   0x40,
    PWM_CHANNEL_OC0B       =   0x40,         
    PWM_CHANNEL_OC1A       =   0x80,
    PWM_CHANNEL_OC1B       =   0x80,
    PWM_CHANNEL_OC2A       =   0xB0,
    PWM_CHANNEL_OC2B       =   0xB0,

    PWM_CHANNEL_END
};


typedef enum _COMPARE_OUTPUT_MODE COMPARE_OUTPUT_MODE;
enum _COMPARE_OUTPUT_MODE
{
    COMPARE_OUTPUT_NORMAL          =   0,
    COMPARE_OUTPUT_TOGGLE          =   1,
    COMPARE_OUTPUT_CLEAR           =   2,
    COMPARE_OUTPUT_SET             =   3,
    
    COMPARE_OUTPUT_MODE_END
};

typedef enum _WAVE_GENERATION_MODE WAVE_GENERATION_MODE;
enum _WAVE_GENERATION_MODE
{
    NORMAL_0xFF                         =   0,
    PHASE_CORRECT_OxFF                  =   1,
    CLEAR_TIME_ON_COMPARE_MATCH_OCRx    =   2,
    FAST_PWM_OxFF                       =   3,
    RESERVED_0                          =   4,
    PHASE_CORRECT_OCRx                  =   5,
    RESERVED_1                          =   6,
    FAST_PWM_OCRx                       =   7,

    WAVE_GENERATION_MODE_END
};

typedef enum _PRESCALE_SELECT_BIT PRESCALE_SELECT_BIT;
enum _PRESCALE_SELECT_BIT
{
    NO_CLOCK_SOURCE                 =   0,
    PWM_PRESCALE_1                  =   1,
    PWM_PRESCALE_8                  =   2,
    PWM_PRESCALE_64                 =   3,
    PWM_PRESCALE_256                =   4,
    PWM_PRESCALE_1024               =   5,
    PWM_EXTERNAL_PRESCALE_T0_RIS    =   6,
    PWM_EXTERNAL_PRESCALE_T0_FAL    =   7,

    PRESCALE_SELECT_BIT_END
};
#endif