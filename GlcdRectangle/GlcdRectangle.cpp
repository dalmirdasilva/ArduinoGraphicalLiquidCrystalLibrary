/**
 * Arduino Graphic LCD Library
 * 
 * GlcdRectangle.cpp
 * 
 * A GlcdRectangle is rectangle in the glcd screen.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP_
#define __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP__ 1

#include "GlcdRectangle.h"

GlcdRectangle::GlcdRectangle() {
    GlcdRectangle(0, 0, 0, 0);
}

GlcdRectangle::GlcdRectangle(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom) : top(top), left(left), right(right), bottom(bottom) {
}

void GlcdRectangle::setTop(unsigned char top) {
    this->top = top;
}

unsigned char GlcdRectangle::getTop() {
    return top;
}

void GlcdRectangle::setLeft(unsigned char left) {
    this->left = left;
}

unsigned char GlcdRectangle::getLeft() {
    return left;
}

void GlcdRectangle::setRight(unsigned char right) {
    this->right = right;
}

unsigned char GlcdRectangle::getRight() {
    return right;
}

void GlcdRectangle::setBottom(unsigned char bottom) {
    this->bottom = bottom;
}

unsigned char GlcdRectangle::getBottom() {
    return bottom;
}

unsigned char GlcdRectangle::getWidth() {
    return (bottom - top);
}

unsigned char GlcdRectangle::getHeight() {
    return (right - left);
}

unsigned int GlcdRectangle::getArea() {
    return (unsigned int) (getWidth() * getHeight());
}

#endif /* __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP__ */