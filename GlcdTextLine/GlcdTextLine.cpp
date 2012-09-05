/**
 * Arduino Graphic LCD Library
 * 
 * GlcdTextLine.cpp
 * 
 * The functions to draw text in a glcd always at the same line.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_TEXT_LINE_CPP__
#define __ARDUINO_LIBRARY_GLCD_TEXT_LINE_CPP__ 1

#include "GlcdTextLine.h"

GlcdTextLine::GlcdTextLine(GlcdText *glcdText, GlcdDrawer *glcdDrawer, unsigned char y) : glcdText(glcdText), glcdDrawer(glcdDrawer) {
    this->y = y;
}

void GlcdTextLine::printLines(const unsigned char *text, unsigned char count) {
    unsigned char realCharacterHeight, printedText = 0;
    realCharacterHeight = glcdText->getFont()->getCharacterHeight() + glcdText->getGraphicState()->getLeading();
    GlcdRectangle printableArea(0, y, GLCD_WIDTH - 1, y + realCharacterHeight);
    while (1) {
        int printed;
        glcdDrawer->getGraphicState()->invertColor();
        glcdDrawer->rect(printableArea.getLeft(), printableArea.getTop(), printableArea.getRight(), printableArea.getBottom());
        glcdDrawer->getGraphicState()->invertColor();
        printed = glcdText->printString(&printableArea, &text[printedText], count);
        if (printed == 0) {
            break;
        }
        glcdText->getGlcd()->scroll(Glcd::CHIP_ALL, Glcd::SCROLL_UP, realCharacterHeight);
        printedText += printed;
    }
}

#endif /* __ARDUINO_LIBRARY_GLCD_TEXT_LINE_CPP__ */
