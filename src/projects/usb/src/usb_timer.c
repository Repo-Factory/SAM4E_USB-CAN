#include <asf.h>
#include "usb_enable.h"

#define CLOCK_CONFIGURE_CONST 1000
#define CALLBACK_PERIOD 100

void systick_init(void)
{
    SysTick_Config(SystemCoreClock/CLOCK_CONFIGURE_CONST);
    NVIC_EnableIRQ(SysTick_IRQn);
}

volatile static void(*timer_callback)(void)=NULL;
void set_timer_callback(void(*callback)(void))
{
    systick_init();
    timer_callback = callback;
}

volatile static int tickcount=0;
void SysTick_Handler(void)
{
	if (++tickcount==CALLBACK_PERIOD)
	{
        if (usb_enabled && timer_callback) 
        {
            timer_callback();
        }
		tickcount = 0;
	}
}