#ifndef __LED_H
#define __LED_H

#include "ch32f20x.h"

#define LED_PORT    GPIOB   
#define LED_LF_PIN  GPIO_Pin_2
#define LED_RF_PIN  GPIO_Pin_1
#define LED_LB_PIN  GPIO_Pin_8
#define LED_RB_PIN  GPIO_Pin_9

typedef enum
{
    LED_LF = 0, /* 左前方LED */
    LED_RF,     /* 右前方LED */
    LED_LB,     /* 左后方LED */
    LED_RB      /* 右后方LED */
} which_led_e;

typedef enum
{
    ON = 0,
    OFF,
    TOGGLE
} led_status_e;

void led_init(void);
void led_set(which_led_e led, led_status_e status);

#endif
