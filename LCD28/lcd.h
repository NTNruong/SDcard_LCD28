#ifndef LCD_H
#define LCD_H
#include "fonts.h"
#include "main.h"

/* choose a Hardware SPI port to use. */
#define LCD_SPI_PORT hspi1
extern SPI_HandleTypeDef LCD_SPI_PORT;

/* choose whether use DMA or not */
//#define USE_DMA

/* If u need CS control, comment below*/
//#define CFG_NO_CS

/* Pin connection*/
#define LCD_RST_PORT LCD_RST_GPIO_Port
#define LCD_RST_PIN  LCD_RST_Pin
#define LCD_DC_PORT  LCD_DC_GPIO_Port
#define LCD_DC_PIN   LCD_DC_Pin

#ifndef CFG_NO_CS
#define LCD_CS_PORT  LCD_CS_GPIO_Port
#define LCD_CS_PIN   LCD_CS_Pin
#endif

/* Choose a type you are using */
//#define USING_135X240
//#define USING_240X240
//#define USING_170X320
#define USING_240X320


/* Choose a display rotation you want to use: (0-3) */
//#define LCD_ROTATION 0
//#define LCD_ROTATION 1
//#define LCD_ROTATION 2				//  use Normally on 240x240
//#define LCD_ROTATION 3
#define LCD_ROTATION 4

#ifdef USING_135X240

    #if LCD_ROTATION == 0
        #define LCD_WIDTH 135
        #define LCD_HEIGHT 240
        #define X_SHIFT 53
        #define Y_SHIFT 40
    #endif

    #if LCD_ROTATION == 1
        #define LCD_WIDTH 240
        #define LCD_HEIGHT 135
        #define X_SHIFT 40
        #define Y_SHIFT 52
    #endif

    #if LCD_ROTATION == 2
        #define LCD_WIDTH 135
        #define LCD_HEIGHT 240
        #define X_SHIFT 52
        #define Y_SHIFT 40
    #endif

    #if LCD_ROTATION == 3
        #define LCD_WIDTH 240
        #define LCD_HEIGHT 135
        #define X_SHIFT 40
        #define Y_SHIFT 53
    #endif

#endif

#ifdef USING_240X240

    #define LCD_WIDTH 240
    #define LCD_HEIGHT 240

		#if LCD_ROTATION == 0
			#define X_SHIFT 0
			#define Y_SHIFT 80
		#elif LCD_ROTATION == 1
			#define X_SHIFT 80
			#define Y_SHIFT 0
		#elif LCD_ROTATION == 2
			#define X_SHIFT 0
			#define Y_SHIFT 0
		#elif LCD_ROTATION == 3
			#define X_SHIFT 0
			#define Y_SHIFT 0
		#endif

#endif

#ifdef USING_170X320

	#if LCD_ROTATION == 0
        #define LCD_WIDTH 170
        #define LCD_HEIGHT 320
        #define X_SHIFT 35
        #define Y_SHIFT 0
    #endif

    #if LCD_ROTATION == 1
        #define LCD_WIDTH 320
        #define LCD_HEIGHT 170
        #define X_SHIFT 0
        #define Y_SHIFT 35
    #endif

    #if LCD_ROTATION == 2
        #define LCD_WIDTH 170
        #define LCD_HEIGHT 320
        #define X_SHIFT 35
        #define Y_SHIFT 0
    #endif

    #if LCD_ROTATION == 3
        #define LCD_WIDTH 320
        #define LCD_HEIGHT 170
        #define X_SHIFT 0
        #define Y_SHIFT 35
    #endif

#endif


#ifdef USING_240X320

    #define LCD_WIDTH 240
    #define LCD_HEIGHT 320

		#if LCD_ROTATION == 0
			#define X_SHIFT 0
			#define Y_SHIFT 80
		#elif LCD_ROTATION == 1
			#define X_SHIFT 80
			#define Y_SHIFT 0
		#elif LCD_ROTATION == 2
			#define X_SHIFT 0
			#define Y_SHIFT 0
		#elif LCD_ROTATION == 3
			#define X_SHIFT 0
			#define Y_SHIFT 0
		#elif LCD_ROTATION == 4
			#define X_SHIFT 0
			#define Y_SHIFT 0
		#endif

#endif

/**
 *Color of pen
 *If you want to use another color, you can choose one in RGB565 format.
 */

#define WHITE       0xFFFF
#define BLACK       0x0000
#define BLUE        0x001F
#define RED         0xF800
#define MAGENTA     0xF81F
#define GREEN       0x07E0
#define CYAN        0x7FFF
#define YELLOW      0xFFE0
#define GRAY        0X8430
#define BRED        0XF81F
#define GRED        0XFFE0
#define GBLUE       0X07FF
#define BROWN       0XBC40
#define BRRED       0XFC07
#define DARKBLUE    0X01CF
#define LIGHTBLUE   0X7D7C
#define GRAYBLUE    0X5458

#define LIGHTGREEN  0X841F
#define LGRAY       0XC618
#define LGRAYBLUE   0XA651
#define LBBLUE      0X2B12

/* Control Registers and constant codes */
#define LCD_NOP     0x00
#define LCD_SWRESET 0x01
#define LCD_RDDID   0x04
#define LCD_RDDST   0x09

#define LCD_SLPIN   0x10
#define LCD_SLPOUT  0x11
#define LCD_PTLON   0x12
#define LCD_NORON   0x13

#define LCD_INVOFF  0x20
#define LCD_INVON   0x21
#define LCD_DISPOFF 0x28
#define LCD_DISPON  0x29
#define LCD_CASET   0x2A
#define LCD_RASET   0x2B
#define LCD_RAMWR   0x2C
#define LCD_RAMRD   0x2E

#define LCD_PTLAR   0x30
#define LCD_COLMOD  0x3A
#define LCD_MADCTL  0x36

/**
 * Memory Data Access Control Register (0x36H)
 * MAP:     D7  D6  D5  D4  D3  D2  D1  D0
 * param:   MY  MX  MV  ML  RGB MH  -   -
 *
 */

/* Page Address Order ('0': Top to Bottom, '1': the opposite) */
#define LCD_MADCTL_MY  0x80
/* Column Address Order ('0': Left to Right, '1': the opposite) */
#define LCD_MADCTL_MX  0x40
/* Page/Column Order ('0' = Normal Mode, '1' = Reverse Mode) */
#define LCD_MADCTL_MV  0x20
/* Line Address Order ('0' = LCD Refresh Top to Bottom, '1' = the opposite) */
#define LCD_MADCTL_ML  0x10
/* RGB/BGR Order ('0' = RGB, '1' = BGR) */
#define LCD_MADCTL_RGB 0x00

#define LCD_RDID1   0xDA
#define LCD_RDID2   0xDB
#define LCD_RDID3   0xDC
#define LCD_RDID4   0xDD

/* Advanced options */
#define LCD_COLOR_MODE_16bit 0x55    //  RGB565 (16bit)
#define LCD_COLOR_MODE_18bit 0x66    //  RGB666 (18bit)

/* Basic operations */
#define LCD_RST_Clr() HAL_GPIO_WritePin(LCD_RST_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_RESET)
#define LCD_RST_Set() HAL_GPIO_WritePin(LCD_RST_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_SET)

#define LCD_DC_Clr() HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_RESET)
#define LCD_DC_Set() HAL_GPIO_WritePin(LCD_DC_GPIO_PORT, LCD_DC_PIN, GPIO_PIN_SET)
#ifndef CFG_NO_CS
#define LCD_Select() HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)
#define LCD_UnSelect() HAL_GPIO_WritePin(LCD_CS_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#else
#define LCD_Select() asm("nop")
#define LCD_UnSelect() asm("nop")
#endif


#define LCD_CS_PIN                                 LCD_CS_Pin
#define LCD_CS_GPIO_PORT                           LCD_CS_GPIO_Port

#define LCD_BL_PIN                                 LCD_BL_Pin
#define LCD_BL_GPIO_PORT                           LCD_BL_GPIO_Port

#define LCD_DC_PIN                                 LCD_DC_Pin
#define LCD_DC_GPIO_PORT                           LCD_DC_GPIO_Port
/*------------------------------------------------------------------------------------------------------*/
#define LCD_RST_PIN                                 LCD_RST_Pin
#define LCD_RST_GPIO_PORT                           LCD_RST_GPIO_Port


#define ABS(x) ((x) > 0 ? (x) : -(x))

/* Basic functions. */
void LCD_Init(void);
void LCD_SetRotation(uint8_t m);
void LCD_Fill_Color(uint16_t color);
void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void LCD_Fill(uint16_t xSta, uint16_t ySta, uint16_t xEnd, uint16_t yEnd, uint16_t color);
void LCD_DrawPixel_4px(uint16_t x, uint16_t y, uint16_t color);

/* Graphical functions. */
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void LCD_DrawCircle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);
void LCD_DrawImage(uint16_t x, uint16_t y, uint16_t w, uint16_t h, const uint16_t *data);
void LCD_InvertColors(uint8_t invert);

/* Text functions. */
void LCD_WriteChar(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor);
void LCD_WriteString(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor);

/* Extented Graphical functions. */
void LCD_DrawFilledRectangle(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
void LCD_DrawTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);
void LCD_DrawFilledTriangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, uint16_t color);
void LCD_DrawFilledCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

/* Command functions */
void LCD_TearEffect(uint8_t tear);

/* Simple test function. */
void LCD_Test(void);

#ifndef LCD_ROTATION
    #error You should at least choose a display rotation!
#endif

#endif
