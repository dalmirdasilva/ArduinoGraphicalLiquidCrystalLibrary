/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalPoint.cpp
 * 
 * A point is pixel in the glcd screen. Point has a x and y positions.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include <GraphicalLiquidCrystalPoint.h>

GraphicalLiquidCrystalPoint::GraphicalLiquidCrystalPoint()
        : GraphicalLiquidCrystalPoint(0, 0) {
}

GraphicalLiquidCrystalPoint::GraphicalLiquidCrystalPoint(unsigned char x, unsigned char y) {
    this->x = x;
    this->y = y;
}

void GraphicalLiquidCrystalPoint::setX(unsigned char x) {
    this->x = x;
}

unsigned char GraphicalLiquidCrystalPoint::getX() {
    return x;
}

void GraphicalLiquidCrystalPoint::setY(unsigned char y) {
    this->y = y;
}

unsigned char GraphicalLiquidCrystalPoint::getY() {
    return y;
}
