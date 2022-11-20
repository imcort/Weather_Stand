#include "sharp_memory_lcd.h"

#include "app_timer.h"

#define SHARPMEM_BIT_WRITE          (0x01)
#define SHARPMEM_BIT_VCOM           (0x02)
#define SHARPMEM_BIT_CLEAR          (0x04)

#define LINE_BUFFER_LENGTH          ((3+5+8+SHARPMEM_WIDTH+16)/8)

static uint8_t sharpmem_line_buffer[LINE_BUFFER_LENGTH];
static const uint8_t set[] = {1, 2, 4, 8, 16, 32, 64, 128},
                     clr[] = {(uint8_t)~1,  (uint8_t)~2,  (uint8_t)~4,
                              (uint8_t)~8,  (uint8_t)~16, (uint8_t)~32,
                              (uint8_t)~64, (uint8_t)~128};

APP_TIMER_DEF(vcom_timer);
#define VCOM_TICK_PERIOD            100
                 
static void vcom_timer_handler(void *p_context)
{
	nrf_gpio_pin_toggle(SHARPMEM_PIN_COM);
}
                              
bool disp_init(void){
    
    pinMode(SHARPMEM_PIN_COM, OUTPUT);
    pinMode(SHARPMEM_PIN_DISP, OUTPUT);
    pinMode(SHARPMEM_PIN_CS, OUTPUT);
    spi_init();
    
    digitalWrite(SHARPMEM_PIN_CS, 0);       //Disable CS.
    digitalWrite(SHARPMEM_PIN_DISP, 0);     //Disable screen.
    
    ret_code_t err_code;
    err_code = app_timer_create(&vcom_timer, APP_TIMER_MODE_REPEATED, vcom_timer_handler);
    APP_ERROR_CHECK(err_code);
    
    err_code = app_timer_start(vcom_timer, APP_TIMER_TICKS(VCOM_TICK_PERIOD), NULL);
    APP_ERROR_CHECK(err_code);

    digitalWrite(SHARPMEM_PIN_DISP, 1);     //Enable screen.

    return true;
	
}

void disp_update_u8(uint8_t start_line, uint8_t* line_buffer)
{
	
	sharpmem_line_buffer[0] = SHARPMEM_BIT_WRITE;
    sharpmem_line_buffer[1] = start_line + 1;
	
	for(int i = 0; i < SHARPMEM_WIDTH; i++){
		
		if(!line_buffer[i]){
			
			sharpmem_line_buffer[(i + 16) / 8] |= set[i & 7];
		
		} else {
		
			sharpmem_line_buffer[(i + 16) / 8] &= clr[i & 7];
		
		}
	
	}
	
    digitalWrite(SHARPMEM_PIN_CS, 1);
	spi_send(sharpmem_line_buffer, LINE_BUFFER_LENGTH);
    digitalWrite(SHARPMEM_PIN_CS, 0);
}

void disp_update_bit(uint8_t start_line, uint8_t* line_buffer)
{
	
	sharpmem_line_buffer[0] = SHARPMEM_BIT_WRITE;
    sharpmem_line_buffer[1] = start_line + 1;
	
	memcpy(sharpmem_line_buffer + 2, line_buffer, SHARPMEM_WIDTH / 8);
	
    digitalWrite(SHARPMEM_PIN_CS, 1);
	spi_send(sharpmem_line_buffer, LINE_BUFFER_LENGTH);
    digitalWrite(SHARPMEM_PIN_CS, 0);
}

void disp_clear(void)
{
	
	memset(sharpmem_line_buffer, 0xff, LINE_BUFFER_LENGTH);
	sharpmem_line_buffer[0] = (SHARPMEM_BIT_CLEAR);
	
	digitalWrite(SHARPMEM_PIN_CS, 1);
	spi_send(sharpmem_line_buffer, LINE_BUFFER_LENGTH);
    digitalWrite(SHARPMEM_PIN_CS, 0);

}
