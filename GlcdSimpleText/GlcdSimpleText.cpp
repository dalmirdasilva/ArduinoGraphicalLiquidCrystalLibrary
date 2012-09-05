/**
 * Arduino - Glcd library
 * 
 * GlcdSimpleText.cpp
 * 
 * The function bodies to draw text in a glcd plane
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_SIMPLE_TEXT_CPP__
#define __ARDUINO_LIBRARY_GLCD_SIMPLE_TEXT_CPP__ 1

#include "GlcdSimpleText.h"

GlcdSimpleText::GlcdSimpleText(Glcd *glcd, GlcdBitmapFont *font, GlcdGraphicState *graphicState) : GlcdText(glcd, font, graphicState) {
}

void GlcdSimpleText::printChar(int x, int y, const unsigned char c, int size) {

    unsigned char rows, column, glyphBuf[font->getGlyphLength()];
    
    // Convert pixel to row.
    y /= (GLCD_HEIGHT / 8);
    
    // Read char data
    font->readGlyphData(glyphBuf, c);

    // Loop through character byte data
    for (unsigned char i = 0; i < font->getCharacterWidth(); i++) {
        
        // Rows
        rows = font->getCharacterHeight() / 8;
        
        // Loop for all columns.
        for (unsigned char j = 0; j < rows; j++) {

            // Column
            column = glyphBuf[j * font->getCharacterWidth() + i];    
            
            // Streaks the column.
            glcd->streak(x + i, y, column);
        }
    }
}

#endif /* __ARDUINO_LIBRARY_GLCD_SIMPLE_TEXT_CPP__ */
