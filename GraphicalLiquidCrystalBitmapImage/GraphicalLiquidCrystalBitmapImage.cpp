/**
 * Arduino Graphic Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalBitmapImage.cpp
 * 
 * The representation of a glcd image.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalBitmapImage.h"
#include <SeekableInputStream.h>

GraphicalLiquidCrystalBitmapImage::GraphicalLiquidCrystalBitmapImage(SeekableInputStream* inputStream)
        : inputStream(inputStream) {
    dataOffset = sizeof(Header);
    inputStream->seek(0);
    header.info = inputStream->read();
    header.width = inputStream->read();
    header.height = inputStream->read();
}

unsigned char GraphicalLiquidCrystalBitmapImage::getInfo() {
    return header.info;
}

unsigned char GraphicalLiquidCrystalBitmapImage::getWidth() {
    return header.width;
}

unsigned char GraphicalLiquidCrystalBitmapImage::getHeight() {
    return header.height;
}

bool GraphicalLiquidCrystalBitmapImage::getPixel(unsigned char x, unsigned char y) {
    unsigned int position;
    unsigned char v;
    position = (y / 8) * getWidth();
    y %= 8;
    position += x;
    inputStream->seek(dataOffset + position);
    v = inputStream->read();
    return v & (0x80 >> y);
}

void GraphicalLiquidCrystalBitmapImage::readColumn(unsigned char* buf, unsigned char col) {
    unsigned char i, rows = getHeight() / 8;
    inputStream->seek(dataOffset + col);
    for (i = 0; i < rows; i++) {
        buf[i] = inputStream->read();
        inputStream->skip(getWidth() - 1);
    }
}

void GraphicalLiquidCrystalBitmapImage::readRow(unsigned char* buf, unsigned char row) {
    inputStream->seek(dataOffset + row * getWidth());
    inputStream->read(buf, 0, getWidth());
}
