/**
* @ file lvgl_spi_conf.h
*
*/

#ifndef LVGL_SPI_CONF_H
#define LVGL_SPI_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
*      INCLUDES
*********************/

/*********************
*      DEFINES
*********************/
// DISPLAY PINS
#define DISP_SPI_MOSI CONFIG_LVGL_DISP_SPI_MOSI
#define DISP_SPI_CLK CONFIG_LVGL_DISP_SPI_CLK
#define DISP_SPI_CS CONFIG_LVGL_DISP_SPI_CS

// TOUCHPAD PINS
#define TP_SPI_MOSI CONFIG_LVGL_TOUCH_SPI_MOSI
#define TP_SPI_MISO CONFIG_LVGL_TOUCH_SPI_MISO
#define TP_SPI_CLK  CONFIG_LVGL_TOUCH_SPI_CLK
#define TP_SPI_CS   CONFIG_LVGL_TOUCH_SPI_CS

#define ENABLE_TOUCH_INPUT  CONFIG_LVGL_ENABLE_TOUCH

#if CONFIG_LVGL_TFT_DISPLAY_SPI_HSPI == 1
#define TFT_SPI_HOST HSPI_HOST
#else
#define TFT_SPI_HOST VSPI_HOST
#endif /*CONFIG_LVGL_TFT_DISPLAY_SPI_HSPI == 1*/

#if CONFIG_LVGL_TOUCH_CONTROLLER_SPI_HSPI == 1
#define TOUCH_SPI_HOST HSPI_HOST
#else
#define TOUCH_SPI_HOST VSPI_HOST
#endif /*CONFIG_LVGL_TOUCH_CONTROLLER_SPI_HSPI == 1*/

// Detect the use of a shared SPI Bus and verify the user specified the same SPI bus for both touch and tft
#if defined (CONFIG_LVGL_TOUCH_DRIVER_PROTOCOL_SPI) && TP_SPI_MOSI == DISP_SPI_MOSI && TP_SPI_CLK == DISP_SPI_CLK
#if TFT_SPI_HOST != TOUCH_SPI_HOST
#error You must specify the same SPI host (HSPI or VSPI) for both display and touch driver
#endif

#define SHARED_SPI_BUS
#endif

/**********************
*      TYPEDEFS
**********************/
#if defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9488)

#define SPI_BUS_MAX_TRANSFER_SZ (DISP_BUF_SIZE * 3)

#elif defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9341)  || \
defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789)   || \
defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_HX8357)   || \
defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107)

#define SPI_BUS_MAX_TRANSFER_SZ (DISP_BUF_SIZE * 2)

#else
#pragma message "No SPI display controller being used"
#define SPI_BUS_MAX_TRANSFER_SZ (DISP_BUF_SIZE * 2)
#endif

#if defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789)
#define SPI_TFT_CLOCK_SPEED_HZ  (24*1000*1000)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_HX8357
#define SPI_TFT_CLOCK_SPEED_HZ  (26*1000*1000)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_SH1107
#define SPI_TFT_CLOCK_SPEED_HZ  (8*1000*1000)
#elif defined CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ILI9486
#define SPI_TFT_CLOCK_SPEED_HZ  (24*1000*1000)
#else
#define SPI_TFT_CLOCK_SPEED_HZ  (60*1000*1000)
#endif

#if defined (CONFIG_LVGL_TFT_DISPLAY_CONTROLLER_ST7789)
#define SPI_TFT_SPI_MODE    (2)
#else
#define SPI_TFT_SPI_MODE    (0)
#endif

/* Touch driver */
#if (CONFIG_LVGL_TOUCH_CONTROLLER == TOUCH_CONTROLLER_STMPE610)
#define SPI_TOUCH_CLOCK_SPEED_HZ    (1*1000*1000)
#define SPI_TOUCH_SPI_MODE          (1)
#else
#define SPI_TOUCH_CLOCK_SPEED_HZ    (2*1000*1000)
#define SPI_TOUCH_SPI_MODE          (0)
#endif

/**********************
* GLOBAL PROTOTYPES
**********************/

/**********************
*      MACROS
**********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LVGL_SPI_CONF_H*/