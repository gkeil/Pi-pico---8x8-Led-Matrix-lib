/******************************************************************
 * 
 *  pico_port_c
 * 
 * 
 *  This file contains the specific Pi pico functions to 
 *  access the 8x8 displays connected via SPI 
 * 
 *  function list if applies
 * 
 *  ver:    1.0
 * 
 *  date:   24-jun-23
 * 
 * *****************************************************************/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "spi_config.h"


/**************************************
 * 
 *  cs_select()
 * 
 *  This function lows the GPIO designated to be connected
 *  to the CS of the display chains. The CS line is active low.
 * 
 *  This routine is taken from pico sdk documentation book
 * 
 *  ver:    1.0
 * 
 *  date:   24-jun-23
 * 
 * ************************************/
static inline void cs_select() 
{
    asm volatile("nop \n nop \n nop");
    gpio_put(CS_GPIO, 0); // Active low
    asm volatile("nop \n nop \n nop");
}


/**************************************
 * 
 *  cs_deselect()
 * 
 *  This function rises the GPIO designated to be connected
 *  to the CS of the display chains. The CS line is active low.
 * 
 *  This routine is taken from pico sdk documentation book
 * 
 *  ver:    1.0
 * 
 *  date:   24-jun-23
 * 
 * ************************************/
static inline void cs_deselect() 
{
    asm volatile("nop \n nop \n nop");
    gpio_put(CS_GPIO, 1);
    asm volatile("nop \n nop \n nop");
}

/**************************************
 * 
 *  write_to_device()
 * 
 *  This routines send a stream of bytes to the SPI devices.
 *  This is part of the port to Raspberry Pi pico
 * 
 *  ver:    1.0
 * 
 *  date:   27-jun-23
 * 
 * ************************************/
void write_to_leds( uint8_t *data, uint8_t len)
{

    // The CS line stays low throughout a "transaction". Send all of the control uint8_ts for all of the chained
    // controllers in a single transaction. When the CS line rises, the data will be latched

    // Cs down
    cs_select();

    // write 2 bytes with command / led status
    spi_write_blocking( SPI_PORT, data, len );

    // cs up
    cs_deselect();

}