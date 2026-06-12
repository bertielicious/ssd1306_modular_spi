#ifndef CONSTANTS_H
#define CONSTANTS_H

/*
SSD1322 pins          GPIO pins
MOSI------------------ 23
SCK------------------- 19
RES------------------- 18
DC-------------------- 21
CS-------------------- 22
*/


#include "stdint.h"
enum{LO, HI};

typedef struct {
    uint8_t sck;
    uint8_t mosi;
    uint8_t cs;
    uint8_t dc;
    uint8_t res;
} display_pins_t;



#endif
/*
OR

static const int MOSI_PIN = 23;
static const int SCK_PIN  = 19;
static const int CS_PIN   = 22;
static const int DC_PIN   = 21;
static const int RST_PIN  = 18;
 
spi_bus_config_t buscfg = {
    .mosi_io_num = MOSI_PIN,
    .sclk_io_num = SCK_PIN,
    .miso_io_num = -1,
};
 
OR

enum DisplayPins {
    PIN_SCK  = 19,
    PIN_MOSI = 23,
    PIN_CS   = 22,
    PIN_DC   = 21,
    PIN_RST  = 18
};
*/