/**
* @file lvgl_driver.h
*
*/

#ifndef LVGL_DRIVER_H
#define LVGL_DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
*      INCLUDES
*********************/
#include <stdbool.h>

#include "lvgl_spi_conf.h"
#include "lvgl_tft/disp_driver.h"
#include "lvgl_touch/touch_driver.h"


/*********************
*      DEFINES
*********************/
#if defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789)
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 40)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_HX8357
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 40)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
#define DISP_BUF_SIZE  (CONFIG_LVGL_DISPLAY_WIDTH*CONFIG_LVGL_DISPLAY_HEIGHT)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9486
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 40)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9488
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 40)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9341
#define DISP_BUF_SIZE  (LV_HOR_RES_MAX * 64)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SSD1306
#define DISP_BUF_SIZE  (CONFIG_LVGL_DISPLAY_WIDTH*CONFIG_LVGL_DISPLAY_HEIGHT)
#else
#error "No display controller selected"
#endif

/**********************
*      TYPEDEFS
**********************/

/**********************
* GLOBAL PROTOTYPES
**********************/
void lvgl_driver_init(void);


bool lvgl_spi_driver_init(int host, int miso_pin, int mosi_pin, int sclk_pin, int max_transfer_sz);
/* Returns true on error */
bool lvgl_i2c_driver_init(int port, int sda_pin, int scl_pin, int speed);

/**********************
*      MACROS
**********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LVGL_DRIVER_H*/