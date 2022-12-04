#include "screen_layout.h"

#include "lvgl.h"
#include "app_timer.h"

#include "apds9960.h"
#include "hdc1080.h"
#include "MS5611.h"
#include "ccs811.h"

#include <time.h>
#include "nrf_calendar.h"

lv_obj_t * time_h_m;
lv_obj_t * date;
lv_obj_t * slogan;

lv_obj_t * temperature;
lv_obj_t * humidity;
lv_obj_t * eco2;
lv_obj_t * tvoc;

lv_obj_t * temperature_label;
lv_obj_t * humidity_label;
lv_obj_t * eco2_label;
lv_obj_t * tvoc_label;

//LV_FONT_DECLARE(datefont);
LV_FONT_DECLARE(miscdispfont);
LV_FONT_DECLARE(miscfont);
LV_FONT_DECLARE(timefont);
//LV_FONT_DECLARE(noto_sans_sc_16);
//LV_FONT_DECLARE(chinese_sc);

APP_TIMER_DEF(sensor_timer);

static void m_sensor_timer_handler(void *p_context)
{
    char disp[100];
    float data;
    data = hdc1080_readTemperature();
    sprintf(disp, "%.2f °C", data);
    lv_label_set_text(temperature, disp);

    data = hdc1080_readHumidity();
    sprintf(disp, "%.2f %%", data);
    lv_label_set_text(humidity, disp);
    
    uint16_t eco2_n, tvoc_n;
    ccs811_getData(&eco2_n, &tvoc_n);
    
    sprintf(disp, "%d ppm", eco2_n);
    lv_label_set_text(eco2, disp);
    
    sprintf(disp, "%d ppm", tvoc_n);
    lv_label_set_text(tvoc, disp);
    
    strftime(disp, 6, "%H:%M", nrf_cal_get_time_calibrated());
    lv_label_set_text(time_h_m, disp);
    
    strftime(disp, 20, "%Y年%m月%d日", nrf_cal_get_time_calibrated());
    lv_label_set_text(date, disp);
    
}

static void timers_create(void)
{
    
    ret_code_t err_code;
	err_code = app_timer_create(&sensor_timer, APP_TIMER_MODE_REPEATED, m_sensor_timer_handler);
    APP_ERROR_CHECK(err_code);

}

static void timers_start(void)
{
    
    ret_code_t err_code;
    err_code = app_timer_start(sensor_timer, APP_TIMER_TICKS(60000), NULL);  //2ms
    APP_ERROR_CHECK(err_code);
    
}

//lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0); 
void layout_begin(void)
{
    time_h_m = lv_label_create(lv_scr_act());
    date = lv_label_create(lv_scr_act());
    slogan = lv_label_create(lv_scr_act());
    
    temperature_label = lv_label_create(lv_scr_act());
    temperature = lv_label_create(lv_scr_act());
    
    humidity_label = lv_label_create(lv_scr_act());
    humidity = lv_label_create(lv_scr_act());
    
    eco2_label = lv_label_create(lv_scr_act());
    eco2 = lv_label_create(lv_scr_act());
    
    tvoc_label = lv_label_create(lv_scr_act());
    tvoc = lv_label_create(lv_scr_act());
    
    lv_obj_set_style_text_font(time_h_m, &timefont, 0);
    lv_obj_set_style_text_font(date, &lv_font_montserrat_8, 0);
//    lv_obj_set_style_text_font(slogan, &chinese_sc, 0);
    
    lv_obj_set_style_text_font(temperature_label, &miscfont, 0);
    lv_obj_set_style_text_font(humidity_label, &miscfont, 0);
    lv_obj_set_style_text_font(eco2_label, &miscfont, 0);
    lv_obj_set_style_text_font(tvoc_label, &miscfont, 0);
    
    lv_obj_set_style_text_font(temperature, &miscdispfont, 0);
    lv_obj_set_style_text_font(humidity, &miscdispfont, 0);
    lv_obj_set_style_text_font(eco2, &miscdispfont, 0);
    lv_obj_set_style_text_font(tvoc, &miscdispfont, 0);
    
    lv_obj_set_width(time_h_m, 215);
    lv_obj_set_width(date, 215);
    lv_obj_set_width(slogan, 215);
//    lv_obj_set_height(temperature, 16);
//    lv_obj_set_height(humidity, 16);
//    lv_obj_set_height(eco2, 16);
//    lv_obj_set_height(tvoc, 16);
    
    lv_obj_align(time_h_m, LV_ALIGN_TOP_LEFT, 0, 5);
    lv_obj_align(date, LV_ALIGN_TOP_LEFT, 0, 65);
    lv_obj_align(slogan, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    
    lv_obj_align(temperature_label, LV_ALIGN_TOP_LEFT, 220, 0);
    lv_obj_align(humidity_label, LV_ALIGN_TOP_LEFT, 220, 60);
    lv_obj_align(eco2_label, LV_ALIGN_TOP_LEFT, 220, 120);
    lv_obj_align(tvoc_label, LV_ALIGN_TOP_LEFT, 220, 180);
    
    lv_obj_align(temperature, LV_ALIGN_TOP_RIGHT, 0, 18);
    lv_obj_align(humidity, LV_ALIGN_TOP_RIGHT, 0, 78);
    lv_obj_align(eco2, LV_ALIGN_TOP_RIGHT, 0, 138);
    lv_obj_align(tvoc, LV_ALIGN_TOP_RIGHT, 0, 198);
    
    //lv_label_set_text(time_h_m, "23:59");
    //lv_label_set_text(date, "2022年11月3日");
    
    lv_label_set_text(temperature_label, "Temperature");
    lv_label_set_text(humidity_label, "Humidity");
    lv_label_set_text(eco2_label, "eCO2");
    lv_label_set_text(tvoc_label, "TVOC");
    
    //lv_label_set_text(slogan, "没有BUG的代码是不完美的！没有BUG的代码是不完美的!");
    
    timers_create();
    timers_start();
    m_sensor_timer_handler(NULL);
}
