#include "write_spi_command.h"
#include "write_spi_data.h"
#include <stdint.h>
void clear_screen(void)
{
    // Clear screen first (horizontal mode is fine for this)
    write_spi_command(0x20); // addressing mode
    write_spi_command(0x00); // horizontal

    write_spi_command(0x21); // column range
    write_spi_command(0x00);
    write_spi_command(0x7F);

    write_spi_command(0x22); // page range
    write_spi_command(0x00);
    write_spi_command(0x07);

    uint8_t clear = 0x24;
    for (int i = 0; i < 1024; i++) 
    {
        write_spi_data(&clear, 1);
    }
}