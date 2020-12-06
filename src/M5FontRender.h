#ifndef M5_FONT_RENDER_H
#define M5_FONT_RENDER_H

#include <stdio.h>
#include <stdarg.h>
//#include <functional>

#if defined( ARDUINO_M5Stack_Core_ESP32 ) || defined( ARDUINO_M5STACK_FIRE )
	#include "M5Stack.h"
#elif defined( ARDUINO_M5STACK_Core2 ) // M5Stack Core2
	#include "M5Core2.h"
#endif
#include "font_render.h"

class M5FontRender {
public:
	bool loadFont(const font_data_t *data, font_data_size_t size);
	bool loadFont(const char *path);
	bool setTextSize(uint16_t size);
	void setTextColor(uint16_t color);
	void setCursor(uint32_t posX, uint32_t posY);
	//void setDrawPixelFunc(function<void>(int32_t x, int32_t y, uint32_t color) _drawPixel);
	void drawString(const char *string, int32_t poX, int32_t poY, uint16_t fg);
	void drawString(const char *string, int32_t poX, int32_t poY);
	void printf(const char* fmt, ...);

protected:
	font_face_t font_face;
	font_render_t font_render;
	const int font_cache_size = 256;
	uint16_t _font_color = 0xFFFF; // white
	uint32_t _posX = 0;
	uint32_t _posY = 0;

	void drawFreetypeBitmap(int32_t cx, int32_t cy, uint16_t bw, uint16_t bh, uint16_t fg, uint8_t *bitmap);
	uint16_t decodeUTF8(uint8_t *buf, uint16_t *index, uint16_t remaining);
	void drawString(const char *string, int32_t poX, int32_t poY, uint16_t fg, font_render_t *render);

	//std::function<void>(int32_t x, int32_t y, uint32_t color) drawPixel = NULL;
};

#endif