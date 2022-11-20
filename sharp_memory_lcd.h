#ifndef __MEMORY_LCD_H__
#define __MEMORY_LCD_H__

#include "transfer_handler.h"

#define SHARPMEM_WIDTH  400
#define SHARPMEM_HEIGHT 240

bool disp_init(void);
void disp_update_u8(uint8_t start_line, uint8_t* line_buffer);
void disp_update_bit(uint8_t start_line, uint8_t* line_buffer);
void disp_clear(void);
#endif
