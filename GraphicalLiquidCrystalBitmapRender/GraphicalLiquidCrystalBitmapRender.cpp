/**
 * Arduino Graphic Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalBitmapRender.cpp
 * 
 * The implementation of functions to draw bitmaps in a module plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalBitmapRender.h"

GraphicalLiquidCrystalBitmapRender::GraphicalLiquidCrystalBitmapRender(GraphicalLiquidCrystal *glcd)
        : glcd(glcd) {
}

void GraphicalLiquidCrystalBitmapRender::drawImage(GraphicalLiquidCrystalBitmapImage* image, unsigned char x, unsigned char y) {
    unsigned char width = image->getWidth();
    unsigned char rows, streak, i, j, k, buf[width];
    rows = image->getHeight() / 8;
    for (i = 0; i < rows; i++) {
        image->readRow(buf, i);
        for (j = 0; j < width; j++) {
            streak = buf[j];
            for (k = 0; k < 8; k++) {
                glcd->plot(x + j, (i * 8) + k + y, (GraphicalLiquidCrystal::Color) (streak & (0x01 << k)));
            }
        }
    }
}

void GraphicalLiquidCrystalBitmapRender::drawImageAtRow(GraphicalLiquidCrystalBitmapImage* image, unsigned char x, unsigned char row) {
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
