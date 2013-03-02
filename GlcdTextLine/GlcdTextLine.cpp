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

GlcdTextLine::GlcdTextLine(GlcdText *glcdText, GlcdDrawer *glcdDrawer,
        unsigned char y) :
        glcdText(glcdText), glcdDrawer(glcdDrawer) {
    this->y = y;
}

void GlcdTextLine::printLines(const unsigned char *text, unsigned char count) {
    unsigned char realCharacterHeight, index = 0;
    realCharacterHeight = glcdText->getFont()->getCharacterHeight()
            + glcdText->getGraphicState()->getLeading();
    Serial.print("realCharacterHeight: ");
    Serial.println(realCharacterHeight);
    Serial.print("y: ");
    Serial.println(y);
    GlcdRectangle area(0, (y & (GLCD_HEIGHT - 1)), GLCD_WIDTH - 1, ((y
            + realCharacterHeight) & (GLCD_HEIGHT - 1)));
    Serial.print("L: ");
    Serial.println(area.getLeft());
    Serial.print("R: ");
    Serial.println(area.getRight());
    Serial.print("T: ");
    Serial.println(area.getTop());
    Serial.print("B: ");
    Serial.println(area.getBottom());
    while (1) {
        unsigned char printed;
        /*
        glcdDrawer->getGraphicState()->invertColor();
        glcdDrawer->drawRectangle(&area);
        glcdDrawer->getGraphicState()->invertColor();
        */
        printed = glcdText->printString(&area, &text[index], count);
        Serial.print("printed:");
        Serial.println(printed);
        if (printed == 0) {
            break;
        }
        area.setBottom((area.getBottom() + realCharacterHeight) & (GLCD_HEIGHT - 1));
        area.setTop((area.getTop() + realCharacterHeight) & (GLCD_HEIGHT - 1));


        Serial.print("sL");
        Serial.println(area.getLeft());
        Serial.print("sR: ");
        Serial.println(area.getRight());
        Serial.print("sT: ");
        Serial.println(area.getTop());
        Serial.print("sB: ");
        Serial.println(area.getBottom());


        y += realCharacterHeight;
        glcdText->getGlcd()->scroll(Glcd::CHIP_ALL, Glcd::SCROLL_UP, realCharacterHeight);
        index += printed;
    }
}

#endif /* __ARDUINO_LIBRARY_GLCD_TEXT_LINE_CPP__ */
