/**
 * Arduino Graphic LCD Library
 * 
 * GlcdPoint.cpp
 * 
 * A point is pixel in the glcd screen. Point has a x and y positions.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_POINT_CPP__
#define __ARDUINO_LIBRARY_GLCD_POINT_CPP__ 1

#include "GlcdPoint.h"

GlcdPoint::GlcdPoint() {
    GlcdPoint(0, 0);
}

GlcdPoint::GlcdPoint(unsigned char x, unsigned char y) {
    this->x = x;
    this->y = y;
}

void GlcdPoint::setX(unsigned char x) {
    this->x = x;
}

unsigned char GlcdPoint::getX() {
    return x;
}

void GlcdPoint::setY(unsigned char y) {
    this->y = y;
}

unsigned char GlcdPoint::getY() {
    return y;
}

#endif /* __ARDUINO_LIBRARY_GLCD_POINT_CPP__ */
