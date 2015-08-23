/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalTextLine.cpp
 * 
 * The functions to draw text in a glcd always at the same line.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalTextLine.h"
#include <GraphicalLiquidCrystal.h>
#include <GraphicalLiquidCrystalRectangle.h>
#include <GraphicalLiquidCrystalText.h>
#include <GraphicalLiquidCrystalDrawer.h>

GraphicalLiquidCrystalTextLine::GraphicalLiquidCrystalTextLine(GraphicalLiquidCrystal *glcd, GraphicalLiquidCrystalText *glcdText, GraphicalLiquidCrystalDrawer *glcdDrawer, unsigned char y)
        : glcd(glcd), glcdText(glcdText), glcdDrawer(glcdDrawer), y(y) {
}

void GraphicalLiquidCrystalTextLine::printLines(const unsigned char *text, unsigned char count) {
    unsigned char realCharacterHeight, index = 0, width, height;
    width = glcd->getWidth();
    height = glcd->getHeight();
    realCharacterHeight = glcdText->getFont()->getCharacterHeight() + glcdText->getGraphicState()->getLeading();
    GraphicalLiquidCrystalRectangle area(0, (y & (height - 1)), width - 1, ((y + realCharacterHeight) & (height - 1)));
    while (1) {
        unsigned char printed;
        printed = glcdText->printString(&area, &text[index], count);
        if (printed == 0) {
            break;
        }
        area.setBottom((area.getBottom() + realCharacterHeight) & (height - 1));
        area.setTop((area.getTop() + realCharacterHeight) & (height - 1));
        y += realCharacterHeight;
        glcd->scroll(GraphicalLiquidCrystal::SCROLL_UP, realCharacterHeight);
        index += printed;
    }
}
