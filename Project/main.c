#include "ch32f20x.h"
#include "rtthread.h"

#include "bsp_uart.h"

#include "led.h"


/*******************************************************************************
  变量声明
*******************************************************************************/
static rt_thread_t led1_thread = RT_NULL;
static rt_thread_t led2_thread = RT_NULL;


/*******************************************************************************
  函数声明
*******************************************************************************/
static void led1_thread_entry (void *parameter);
static void led2_thread_entry (void *parameter);


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main( void )
{ 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    uart_init();
    /*
     * SYSCLK = 144 MHz
     * HCLK   = 144 MHz
     * PCLK1  = 144 MHz
     * PCLK2  = 72  MHz
     */
    printf("System clock frequency: %d Hz\r\n", SystemCoreClock);
    
    led_init();
    
    /* 线程创建 */
    led1_thread = rt_thread_create("led1",
                                   led1_thread_entry,
                                   RT_NULL,
                                   512,
                                   3,
                                   20);
    if (led1_thread != RT_NULL) {
        rt_thread_startup(led1_thread);
    } else {
        return -1;
    }
    
    led2_thread = rt_thread_create("led2",
                                   led2_thread_entry,
                                   RT_NULL,
                                   512,
                                   4,
                                   20);
    if (led2_thread != RT_NULL) {
        rt_thread_startup(led2_thread);
    } else {
        return -1;
    }
    return 0;
}


/*******************************************************************************
  线程定义
*******************************************************************************/
static void led1_thread_entry (void *parameter)
{
    while (1) {
        led_set(LED_LF, TOGGLE);
        rt_thread_delay(500);
    }
}

static void led2_thread_entry (void *parameter)
{
    while (1) {
        led_set(LED_RF, TOGGLE);
        rt_thread_delay(400);
    }
}
