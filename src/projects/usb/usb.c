/* USB Device Port
The device uses the USB communication device class (CDC) drivers to take advantage of the installed PC RS-232
software to talk over the USB. The CDC class is implemented in all releases of Windows ® , beginning with
Windows 98SE. The CDC document, available at www.usb.org, describes a way to implement devices such as
ISDN modems and virtual COM ports.
The Vendor ID (VID) is Atmel’s vendor ID 0x03EB. The product ID (PID) is 0x6124. These references are used by
the host operating system to mount the correct driver. On Windows systems, the INF files contain the
correspondence between vendor ID and product ID.
Host Device
SOH 01 FE Data[128] CRC CRC
C
ACK
SOH 02 FD Data[128] CRC CRC
ACK
SOH 03 FC Data[100] CRC CRC
ACK
EOT
ACK
447SAM4E Series [DATASHEET]
Atmel-11157H-ATARM-SAM4E16-SAM4E8-Datasheet_31-Mar-16
For more details about VID/PID for End Product/Systems, please refer to the Vendor ID form available from the
USB Implementers Forum on www.usb.org.
Atmel provides an INF example to see the device as a new serial port and also provides another custom driver
used by the SAM-BA application: atm6124.sys. Refer to the application note “USB Basic Application”, Atmel
literature number 6123, for more  */

/* 
//    iram_size_t udi_cdc_read_buf(int* buf, iram_size_t size);
//    int udi_cdc_putc(int value);
//    iram_size_t udi_cdc_write_buf(const int* buf, iram_size_t size);  */

#include <asf.h>
#include <stdio.h>
#include "quick_blink.h"
#include "led_f.h"

static bool my_flag_autorize_cdc_transfert = false;
bool my_callback_cdc_enable(void)
{
    my_flag_autorize_cdc_transfert = true;
    return true;
}
void my_callback_cdc_disable(void)
{
    my_flag_autorize_cdc_transfert = false;
}

void hardware_init(void)
{
    sysclk_init();
    board_init();
    cpu_irq_enable();
    udc_start();
}

int main(void) 
{
    hardware_init();
    for (;;)
    {
        if (my_flag_autorize_cdc_transfert) 
        {
            udi_cdc_putc('A');
            udi_cdc_getc();
        }
    }
}