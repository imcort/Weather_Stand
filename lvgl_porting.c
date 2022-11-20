#include "lvgl_porting.h"

#include "sharp_memory_lcd.h"
#include "app_timer.h"

static lv_disp_drv_t disp_drv;          /*A variable to hold the drivers. Must be static or global.*/

void spi_complete()
{
    
    lv_disp_flush_ready(&disp_drv); /* tell lvgl that flushing is done */

}

static void my_flush_cb(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint8_t* pointer = &(color_p->full);
    for (int y = area->y1; y <= area->y2; y++)
    {
        disp_update_u8(y, pointer);
        pointer += SHARPMEM_WIDTH;
    }

    
}

static void my_rounder_cb(lv_disp_drv_t * disp_drv, lv_area_t * area)
{
  /* Update the areas as needed. Can be only larger.
   * For example to always have lines 8 px height:*/
   area->x1 = 0;
   area->x2 = SHARPMEM_WIDTH - 1;
}

static void my_printf(const char * buf)
{
	Debug("lvgl %s",buf);
    NRF_LOG_FLUSH();
}

void lvgl_begin(void){
    
    disp_init();
    disp_clear();
 
    lv_init();
    
    /*A static or global variable to store the buffers*/
    static lv_disp_draw_buf_t disp_buf;

    /*Static or global buffer(s). The second buffer is optional*/
    static lv_color_t buf_1[SHARPMEM_WIDTH * 2];
    //static lv_color_t buf_2[SHARPMEM_WIDTH * 2];

    /*Initialize `disp_buf` with the buffer(s). With only one buffer use NULL instead buf_2 */
    lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, SHARPMEM_WIDTH * 2);
    
    
    lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
    disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
    disp_drv.flush_cb = my_flush_cb;        /*Set a flush callback to draw to the display*/
    disp_drv.rounder_cb = my_rounder_cb;
    disp_drv.hor_res = SHARPMEM_WIDTH;      /*Set the horizontal resolution in pixels*/
    disp_drv.ver_res = SHARPMEM_HEIGHT;     /*Set the vertical resolution in pixels*/

    lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/
	
	lv_log_register_print_cb(my_printf); /* register print function for debugging */
    
    

	
	
}
