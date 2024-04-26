#ifndef __PWM_MODE_H__
#define __PWM_MODE_H__

    // [DDD-PWM-1]
    // TODO : Developer can setup the PWM mode.

typedef enum _PWM_CHANNER PWM_CHANNER;
enum _PWM_CHANNER
{
    PWM_CH0     =   0,
    PWM_CH1     =   1,
    PWM_CH2     =   2,

    PWM_CH_END    
};


typedef enum _COMP_OUTPUT_MODE COMP_OUTPUT_MODE;
enum _COMP_OUTPUT_MODE
{
    COMP_OUTPUT_NORMAL_OPS      =   0,
    COMP_OUTPUT_TOGGLE          =   1,
    COMP_OUTPUT_CLEAR           =   2,
    COMP_OUTPUT_SET             =   3,
    
    COMP_OUTPUT_MODE_END
};

typedef enum _WAVE_GEN_MODE WAVE_GEN_MODE;
enum _WAVE_GEN_MODE
{
    NORMAL_0xFF         =   0,
    PHASE_CORRECT_OxFF  =   1,
    CTC_OCRA            =   2,
    FAST_PWM_OxFF       =   3,
    RESERVED_0          =   4,
    PHASE_CORRECT_OCRA  =   5,
    RESERVED_1          =   6,
    FAST_PWM_OCRA       =   7,

    WAVE_GEN_MODE_END
};

typedef enum _CLK_SELECT_BIT CLK_SELECT_BIT;
enum _CLK_SELECT_BIT
{
    NO_CLOCK_SRC        =   0,
    PWM_PRESCALE_1      =   1,
    PWM_PRESCALE_8      =   2,
    PWM_PRESCALE_64     =   3,
    PWM_PRESCALE_256    =   4,
    PWM_PRESCALE_1024   =   5,
    PWM_EXT_CLK_T0_RIS  =   6,
    PWM_EXT_CLK_T0_FAL  =   7,

    CLK_SELECT_BIT_END
};
#endif