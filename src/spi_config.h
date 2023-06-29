/******************************************************************
 * 
 *  spi_config_h
 * 
 * 
 *  This file contains the definitions for inititializing
 *  and working with the SPI port connected to the 8x8 displays
 * 
 *  function list if applies
 * 
 *  ver:    1.0
 * 
 *  date:   24-jun-23
 * 
 * *****************************************************************/

#include "hardware/spi.h"


// GPIO definitions
#define MOSI_GPIO   3
#define CLK_GPIO    2
#define CS_GPIO     5

// SPI port specific settings
#define SPI_RATE    100*1000
#define SPI_PORT    spi0
