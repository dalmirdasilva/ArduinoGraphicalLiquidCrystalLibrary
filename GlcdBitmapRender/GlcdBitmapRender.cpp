/**
 * Arduino Graphic LCD Library
 * 
 * GlcdBitmapRender.cpp
 * 
 * The implementation of functions to draw bitmaps in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_CPP__
#define __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_CPP__ 1

#include "GlcdBitmapRender.h"

GlcdBitmapRender::GlcdBitmapRender(Glcd *glcd) : glcd(glcd) {
}

void GlcdBitmapRender::drawImage(GlcdBitmapImage* image, unsigned char x, unsigned char y) {
    unsigned char width = image->getWidth();
    unsigned char rows, streak, i, j, k, buf[width];
    rows = image->getHeight() / 8;
    for (i = 0; i < rows; i++) {
        image->readRow(buf, i);
        for (j = 0; j < width; j++) {
            streak = buf[j];
            for (k = 0; k < 8; k++) {
                glcd->plot(x + j, (i * 8) + k + y, (Glcd::Color)(streak & (0x01 << k)));
            }
        }
    }
}

void GlcdBitmapRender::drawImageAtRow(GlcdBitmapImage* image, unsigned char x, unsigned char row) {
    unsigned char width = image->getWidth();
    unsigned char rows, i, j, buf[width];
    rows = image->getHeight() / 8;
    for (i = 0; i < rows; i++) {
        image->readRow(buf, i);
        for (j = 0; j < width; j++) {
            glcd->streak(x + j, row + i, buf[j]);
        }
    }
}

#endif /* __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_CPP__ */
