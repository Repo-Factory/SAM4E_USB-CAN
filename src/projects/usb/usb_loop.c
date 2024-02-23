#include "led_f.h"
#include "usb_enable.h"
#include "usb_timer.h"
#include <stdio.h>
#include <string.h>

#define USB_PACKET_SIZE_BYTES 4
#define ARE_EQUAL(buffer, msg) memcmp(buffer, &msg, sizeof(buffer)) == 0

static unsigned char buffer[USB_PACKET_SIZE_BYTES] = {0};

void enter_loop(void)
{
    for (;;)
    {
    
    }
}

void timer_callback(void)
{
    const int val = udi_cdc_putc('x');
}

int main(void) 
{
    start_usb_cdc();
    set_timer_callback(&timer_callback);
    enter_loop();
}