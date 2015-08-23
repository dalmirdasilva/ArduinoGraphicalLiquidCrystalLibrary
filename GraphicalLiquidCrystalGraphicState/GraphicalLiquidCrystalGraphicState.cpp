/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalGraphicState.cpp
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include <GraphicalLiquidCrystalGraphicState.h>

GraphicalLiquidCrystalGraphicState::GraphicalLiquidCrystalGraphicState()
        : linePattern(SOLID_LINE), fillPattern(SOLID_FILL), color(GraphicalLiquidCrystal::COLOR_WHITE), leading(1), space(1), fill(true) {
}

void GraphicalLiquidCrystalGraphicState::setFillPattern(FillPattern fillPattern) {
    this->fillPattern = fillPattern;
}

GraphicalLiquidCrystalGraphicState::FillPattern GraphicalLiquidCrystalGraphicState::getFillPattern() {
    return fillPattern;
}

void GraphicalLiquidCrystalGraphicState::setLinePattern(LinePattern linePattern) {
    this->linePattern = linePattern;
}

GraphicalLiquidCrystalGraphicState::LinePattern GraphicalLiquidCrystalGraphicState::getLinePattern() {
    return linePattern;
}

void GraphicalLiquidCrystalGraphicState::setLeading(unsigned char leading) {
    this->leading = leading;
}

unsigned char GraphicalLiquidCrystalGraphicState::getLeading() {
    return leading;
}

void GraphicalLiquidCrystalGraphicState::setColor(GraphicalLiquidCrystal::Color color) {
    this->color = color;
}

GraphicalLiquidCrystal::Color GraphicalLiquidCrystalGraphicState::getColor() {
    return color;
}

void GraphicalLiquidCrystalGraphicState::invertColor() {
    color = (GraphicalLiquidCrystal::Color) ~color;
}

void GraphicalLiquidCrystalGraphicState::setSpace(unsigned char space) {
    this->space = space;
}

unsigned char GraphicalLiquidCrystalGraphicState::getSpace() {
    return space;
}

void GraphicalLiquidCrystalGraphicState::setFill(bool fill) {
    this->fill = fill;
}

bool GraphicalLiquidCrystalGraphicState::getFill() {
    return fill;
}
