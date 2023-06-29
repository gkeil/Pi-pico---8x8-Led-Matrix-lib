/**
 * 
 * Sample 8x8 led controlling from pico sdk documentation.
 * 
 * 
*/

#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/spi.h"


// local definitions
#define MOSI_GPIO   3
#define CLK_GPIO    2
#define CS_GPIO     5




/*
    This routines are taken from pico sdk documentation book
*/

static inline void cs_select() 
{
    asm volatile("nop \n nop \n nop");
    gpio_put(CS_GPIO, 0); // Active low
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() 
{
    asm volatile("nop \n nop \n nop");
    gpio_put(CS_GPIO, 1);
    asm volatile("nop \n nop \n nop");
}

void write_to_leds( uint8_t *row, int len)
{
    // Cs down
    cs_select();

    // write 2 bytes with command / led status
    spi_write_blocking( spi0, row, len);

    // cs up
    cs_deselect();

}

#if 0

#endif

/***
 * 
 * Main entry point
*/

void main()
{
    uint8_t row[10];
    int i;
    uint8_t mask, content;

    // start

    stdio_init_all();

    printf("*** Sample 8x8 Led Matrix ***\n");

    // initialize SPI 0 port
    spi_init( spi0, 1000 * 1000);             // set to 1 Mh
    gpio_set_function(MOSI_GPIO, GPIO_FUNC_SPI);
    gpio_set_function(CLK_GPIO,  GPIO_FUNC_SPI);

    // Chip select is active-low, so we'll initialise it to a driven-high state
    gpio_init(CS_GPIO);
    gpio_set_dir(CS_GPIO, GPIO_OUT);
    gpio_put(CS_GPIO, 1);


    // time for truth. 

    
        // shutdown mode
        row[0] = 0x0C;
        row[1] = 0x00;
        row[2] = 0x0C;
        row[3] = 0x00;

        write_to_leds(row,4);
        

        // set scan limit
        row[0] = 0x0B;
        row[1] = 0x07;
        row[2] = 0x0B;
        row[3] = 0x07;

        write_to_leds(row,4);

        // exit test mode
        row[0] = 0x0F;
        row[1] = 0x00;
        row[2] = 0x0F;
        row[3] = 0x00;


        write_to_leds(row,4);

        // clear all leds
        for ( i = 1; i <= 8; i++)
        {
            row[0] = i;
            row[1] = 0;
            row[2] = i;
            row[3] = 0;

            write_to_leds(row,4);

        }


        // exit shutdown mode
        row[0] = 0x0C;
        row[1] = 0x01;
        row[2] = 0x0C;
        row[3] = 0x01;

        write_to_leds(row,4);

        // initialization complet -------------------------

        sleep_ms(2000);

        // turn on 2 leds
        //row[0] = 0x01;
        //row[1] = 0x03;

        //write_to_leds(row);

    while (true)
    {

    
        mask    = 0x01;
        content = 0x00;

        // turn leds on with style
        for ( i = 1; i <= 8; i++)
        {
            mask = 0x01 << (i-1);
            content += mask;
            
            printf("i=%d Mask=%d cont=%d\n",i,mask,content);


            row[0] = i;
            row[1] = content;
            row[2] = i;
            row[3] = content;


            write_to_leds(row,4);
            sleep_ms( 200 );

        }

        // clear rows
        for ( i = 8; i >= 1; i--)
        {
            
            row[0] = i;
            row[1] = 0;
            row[2] = i;
            row[3] = 0;


            write_to_leds(row,4);
            sleep_ms( 200 );

        }


    }
    
    

}