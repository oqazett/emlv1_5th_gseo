#ifndef __PWM_MODE_H__
#define __PWM_MODE_H__

    // [DDD-PWM-1]
    // TODO : Developer can setup the PWM mode.

#define DEBUG_MESSAGE   1

typedef enum _PWM_TIMER_COUNTER_NUMBER PWM_TIMER_COUNTER_NUMBER;
enum _PWM_TIMER_COUNTER_NUMBER
{
    PWM_TIMER_COUNTER_0       =   0,
    PWM_TIMER_COUNTER_1       =   1,
    PWM_TIMER_COUNTER_2       =   2,

    PWM_CHANNEL_END
};

typedef enum _OUTPUT_COMPARE_PIN OUTPUT_COMPARE_PIN;
enum _OUTPUT_COMPARE_PIN
{
    OCxA    =   6,
    OCxB    =   4
};

typedef enum _COMPARE_OUTPUT_MODE COMPARE_OUTPUT_MODE;
enum _COMPARE_OUTPUT_MODE
{
    NORMAL_PORT_OPERATION          =   0,
    TOGGLE_ON_MATCH_NORMAL         =   1,
    NON_INVERTING_MODE             =   2,
    INVERTING_MODE                 =   3,
    
    COMPARE_OUTPUT_MODE_END
};

typedef enum _WAVE_GENERATION_MODE WAVE_GENERATION_MODE;
enum _WAVE_GENERATION_MODE
{
    NORMAL_TOP_0xFFFF                   =   0,
    PHASE_CORRECT_8BIT_TOP_0x00FF       =   1,
    PHASE_CORRECT_9BIT_TOP_0x01FF       =   2,
    PHASE_CORRECT_10BIT_TOP_0x01FF      =   3,
    CTC_TOP_OCR1A                       =   4,
    FAST_PWM_8BIT_TOP_0x00FF            =   5,
    FAST_PWM_9BIT_TOP_0x01FF            =   6,
    FAST_PWM_10BIT_TOP_0x03FF           =   7,
    PHASE_AND_FREQ_CORRECT_TOP_ICR1     =   8,
    PHASE_AND_FREQ_CORRECT_TOP_OCR1A    =   9,
    PHASE_CORRECT_TOP_ICR1              =   10,
    PHASE_CORRECT_TOP_OCR1A             =   11,
    CTC_TOP_ICR1                        =   12,
    RESERVED                            =   13,
    FAST_PWM_TOP_ICR1                   =   14,
    FAST_PWM_TOP_OCR1A                  =   15,   

    WAVE_GENERATION_MODE_END
};

typedef enum _TC1_SELECT_PRESCALE_VALUE TC1_SELECT_PRESCALE_VALUE;
enum TC1_SELECT_PRESCALE_VALUE
{                                               // *** If Timer/Counter 0 or 2 ***
    TC1_NO_CLOCK_SOURCE                     =   0,  // 0 : NO_CLOCK_SOURCE      //
    TC1_PRESCALE_1                          =   1,  //
    TC1_PRESCALE_8                          =   2,
    TC1_PRESCALE_64                         =   3,
    TC1_PRESCALE_256                        =   4,
    TC1_PRESCALE_1024                       =   5,
    TC1_EXTERNAL_CLOCK_SOURCE_T1_RISISNG    =   6,
    TC1_EXTERNAL_CLOCK_SOURCE_T1_FALLING    =   7,

    PRESCALE_SELECT_BIT_END
};

typedef enum _TC2_SELECT_PRESCALE_VALUE TC2_SELECT_PRESCALE_VALUE;
enum TC2_SELECT_PRESCALE_VALUE
{
    TC2_NO_CLOCK_SOURCE                     =   0,
    TC2_PRESCALE_1                          =   1,
    TC2_PRESCALE_8                          =   2,
    TC2_PRESCALE_32                         =   3,
    TC2_PRESCALE_64                         =   4,
    TC2_PRESCALE_128                        =   5,
    TC2_PRESCALE_256                        =   6,
    TC2_PRESCALE_1024                       =   7,

    TC2_PRESCALE_SELECT_BIT_END
};
#endif