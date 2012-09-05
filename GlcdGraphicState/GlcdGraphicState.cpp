/**
 * Arduino Graphic LCD Library
 * 
 * GlcdGraphicState.cpp
 * 
 * The glcd graphic state.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_GRAPHIC_STATE_CPP__
#define __ARDUINO_LIBRARY_GLCD_GRAPHIC_STATE_CPP__ 1

#include "GlcdGraphicState.h"

void GlcdGraphicState::setFillPattern(FillPattern fillPattern) {
    this->fillPattern = fillPattern;
}

GlcdGraphicState::FillPattern GlcdGraphicState::getFillPattern() {
    return fillPattern;
}

void GlcdGraphicState::setLinePattern(LinePattern linePattern) {
    this->linePattern = linePattern;
}

GlcdGraphicState::LinePattern GlcdGraphicState::getLinePattern() {
    return linePattern;
}

void GlcdGraphicState::setLeading(unsigned char leading) {
    this->leading = leading;
}

unsigned char GlcdGraphicState::getLeading() {
    return leading;
}

void GlcdGraphicState::setColor(Glcd::Color color) {
    this->color = color;
}

Glcd::Color GlcdGraphicState::getColor() {
    return color;
}

void GlcdGraphicState::invertColor() {
    switch(color) {
        case Glcd::COLOR_BLACK:
            color = Glcd::COLOR_WHITE;
        break;
        case Glcd::COLOR_WHITE:
            color = Glcd::COLOR_BLACK;
        break;
    }
}

void GlcdGraphicState::setSpace(unsigned char space) {
    this->space = space;
}

unsigned char GlcdGraphicState::getSpace() {
    return space;
}

void GlcdGraphicState::setFill(bool fill) {
    this->fill = fill;
}

bool GlcdGraphicState::getFill() {
    return fill;
}

#endif /* __ARDUINO_LIBRARY_GLCD_GRAPHIC_STATE_CPP__ */
