#include <asf.h>
#include <stdio.h>
#include "quick_blink.h"
#include "led_f.h"

volatile static char* this_works = "This shit works bitches. ";

volatile static bool usb_enabled = false;
bool my_callback_cdc_enable(void)
{
    return usb_enabled = true;
}
void my_callback_cdc_disable(void)
{
    usb_enabled = false;
}

#define PERIOD 1000
volatile static int tickcount=0;
void SysTick_Handler(void)
{
	if (++tickcount==100)
	{
        if (usb_enabled) 
        {
            if (*this_works != '\0')
            {
                const int val = udi_cdc_putc(*this_works);
                this_works++;
            } 
            else
            {
                this_works = "This shit works bitches. "; // Reset pointer to beginning of the string
            }
            TOGGLE_LIGHT();
        }
		tickcount = 0;
	}
}

void toggle_on_char(const char ch)
{
    int cdc_line_val = udi_cdc_getc();
    if (cdc_line_val == ch) 
        TOGGLE_LIGHT();
}

void usb_init(void)
{
    udc_start();
    udi_cdc_comm_enable();
    udi_cdc_data_enable();
}

void systick_init(void)
{
    SysTick_Config(SystemCoreClock/PERIOD);
    NVIC_EnableIRQ(SysTick_IRQn);
}

void interrupt_init(void)
{
    irq_initialize_vectors();
    cpu_irq_enable();
}

void hardware_init(void)
{
    sysclk_init();
    interrupt_init();
    board_init();
    usb_init();
    systick_init();
}

void enter_loop(void)
{
    for (;;)
    {
        toggle_on_char('A');
    }
}

int main(void) 
{
    hardware_init();
    enter_loop();
}