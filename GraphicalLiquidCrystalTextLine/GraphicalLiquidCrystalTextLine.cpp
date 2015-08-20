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

GraphicalLiquidCrystalTextLine::GraphicalLiquidCrystalTextLine(GraphicalLiquidCrystalText *glcdText, GraphicalLiquidCrystalDrawer *glcdDrawer, unsigned char y)
        : glcdText(glcdText), glcdDrawer(glcdDrawer) {
    this->y = y;
}

void GraphicalLiquidCrystalTextLine::printLines(const unsigned char *text, unsigned char count) {
    unsigned char realCharacterHeight, index = 0;
    realCharacterHeight = glcdText->getFont()->getCharacterHeight() + glcdText->getGraphicState()->getLeading();
    GraphicalLiquidCrystalRectangle area(0, (y & (GRAPHICAL_LIQUID_CRYSTAL_HEIGHT - 1)), GRAPHICAL_LIQUID_CRYSTAL_WIDTH - 1, ((y + realCharacterHeight) & (GRAPHICAL_LIQUID_CRYSTAL_HEIGHT - 1)));
    while (1) {
        unsigned char printed;
        printed = glcdText->printString(&area, &text[index], count);
        if (printed == 0) {
            break;
        }
        area.setBottom((area.getBottom() + realCharacterHeight) & (GRAPHICAL_LIQUID_CRYSTAL_HEIGHT - 1));
        area.setTop((area.getTop() + realCharacterHeight) & (GRAPHICAL_LIQUID_CRYSTAL_HEIGHT - 1));
        y += realCharacterHeight;
        glcdText->getGraphicalLiquidCrystal()->scroll(GraphicalLiquidCrystal::CHIP_ALL, GraphicalLiquidCrystal::SCROLL_UP, realCharacterHeight);
        index += printed;
    }
}
