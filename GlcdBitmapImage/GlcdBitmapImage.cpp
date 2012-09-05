/**
 * Arduino Graphic LCD Library
 * 
 * GlcdBitmapImage.cpp
 * 
 * The representation of a glcd image.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_BITMAP_IMAGE_CPP__
#define __ARDUINO_LIBRARY_GLCD_BITMAP_IMAGE_CPP__ 1

#include "GlcdBitmapImage.h"

GlcdBitmapImage::GlcdBitmapImage(SeekableInputStream* inputStream) : inputStream(inputStream) {
    dataOffset = sizeof (Header);
    inputStream->seek(0);
    header.info = inputStream->read();
    header.width = inputStream->read();
    header.height = inputStream->read();
}

unsigned char GlcdBitmapImage::getInfo() {
    return header.info;
}

unsigned char GlcdBitmapImage::getWidth() {
    return header.width;
}

unsigned char GlcdBitmapImage::getHeight() {
    return header.height;
}

bool GlcdBitmapImage::getPixel(unsigned char x, unsigned char y) {
    unsigned int position;
    unsigned char v;
    position = (y / 8) * getWidth();
    y %= 8;
    position += x;
    inputStream->seek(dataOffset + position);
    v = inputStream->read();
    return v & (0x80 >> y);
}

void GlcdBitmapImage::readColumn(unsigned char* buf, unsigned char col) {
    unsigned char i, rows = getHeight() / 8;
    inputStream->seek(dataOffset + col); 
    for (i = 0; i < rows; i++) {
        buf[i] = inputStream->read();
        inputStream->skip(getWidth() - 1);
    }
}

void GlcdBitmapImage::readRow(unsigned char* buf, unsigned char row) {
    inputStream->seek(dataOffset + row * getWidth());
    inputStream->read(buf, 0, getWidth());
}

#endif /* __ARDUINO_LIBRARY_GLCD_BITMAP_IMAGE_CPP__ */
