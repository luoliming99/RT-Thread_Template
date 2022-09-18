#include "ch32f20x.h"
#include "bsp_systick.h"
#include "bsp_uart.h"

#include "led.h"


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

    systick_init();
    uart_init();
    /*
     * SYSCLK = 144 MHz
     * HCLK   = 144 MHz
     * PCLK1  = 144 MHz
     * PCLK2  = 72  MHz
     */
    printf("System clock frequency: %d Hz\r\n", SystemCoreClock);
    
    led_init();
    
    while (1)
    {
        led_set(LED_LF, TOGGLE);
        delay_ms(500);
    }
}
