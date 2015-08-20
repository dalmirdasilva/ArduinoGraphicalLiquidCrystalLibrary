/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalRectangle.cpp
 * 
 * A GraphicalLiquidCrystalRectangle is rectangle in the glcd screen.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP_
#define __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP__ 1

#include <GraphicalLiquidCrystalRectangle.h>

GraphicalLiquidCrystalRectangle::GraphicalLiquidCrystalRectangle() : GraphicalLiquidCrystalRectangle(0, 0, 0, 0) {
}

GraphicalLiquidCrystalRectangle::GraphicalLiquidCrystalRectangle(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom) : left(left), top(top), right(right), bottom(bottom) {
}

void GraphicalLiquidCrystalRectangle::setTop(unsigned char top) {
    this->top = top;
}

unsigned char GraphicalLiquidCrystalRectangle::getTop() {
    return top;
}

void GraphicalLiquidCrystalRectangle::setLeft(unsigned char left) {
    this->left = left;
}

unsigned char GraphicalLiquidCrystalRectangle::getLeft() {
    return left;
}

void GraphicalLiquidCrystalRectangle::setRight(unsigned char right) {
    this->right = right;
}

unsigned char GraphicalLiquidCrystalRectangle::getRight() {
    return right;
}

void GraphicalLiquidCrystalRectangle::setBottom(unsigned char bottom) {
    this->bottom = bottom;
}

unsigned char GraphicalLiquidCrystalRectangle::getBottom() {
    return bottom;
}

unsigned char GraphicalLiquidCrystalRectangle::getWidth() {
    return (bottom - top);
}

unsigned char GraphicalLiquidCrystalRectangle::getHeight() {
    return (right - left);
}

unsigned int GraphicalLiquidCrystalRectangle::getArea() {
    return (unsigned int) (getWidth() * getHeight());
}

#endif /* __ARDUINO_LIBRARY_GLCD_RECTANGLE_CPP__ */
