#include "led_f.h"
#include "usb_enable.h"
#include "usb_timer.h"
#include <stdio.h>
#include <string.h>

#define USB_PACKET_SIZE_BYTES 4
#define TIMER_PERIOD 100
#define CLEAR_BUFFER(buffer, size) \
                                    do { \
                                        for (int i = 0; i < (size); i++) { \
                                            (buffer)[i] = 0; \
                                        } \
                                    } while(0)
#define ARE_EQUAL(buffer, msg) memcmp(buffer, &msg, sizeof(buffer)) == 0

static unsigned char buffer[USB_PACKET_SIZE_BYTES] = {0};

void handle_message(const unsigned char* buffer)
{
    
}

void enter_loop(void)
{
    for (;;)
    {
        udi_cdc_read_no_polling((void*)buffer, USB_PACKET_SIZE_BYTES);
        handle_message(buffer);
        CLEAR_BUFFER(buffer, USB_PACKET_SIZE_BYTES);
    }
}

void timer_callback(void)
{
    
}

int main(void) 
{
    start_usb_cdc();
    set_timer_callback(&timer_callback, TIMER_PERIOD);
    enter_loop();
}