/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalSimpleText.cpp
 * 
 * The function bodies to draw text in a glcd plane
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalSimpleText.h"

GraphicalLiquidCrystalSimpleText::GraphicalLiquidCrystalSimpleText(GraphicalLiquidCrystal *glcd, GraphicalLiquidCrystalBitmapFont *font, GraphicalLiquidCrystalGraphicState *graphicState)
        : GraphicalLiquidCrystalText(glcd, font, graphicState) {
}

void GraphicalLiquidCrystalSimpleText::printChar(unsigned char x, unsigned char y, const unsigned char c, unsigned char size) {

    unsigned char rows, column, glyphBuf[font->getGlyphLength()];

    // Convert pixel to row.
    y /= (GRAPHICAL_LIQUID_CRYSTAL_HEIGHT / 8);

    // Read char data
    font->readGlyphData(glyphBuf, c);

    // Loop through character byte data
    for (unsigned char i = 0; i < font->getCharacterWidth(); i++) {

        // Rows
        rows = font->getCharacterHeight() / 8;
        for (unsigned char j = 0; j < rows; j++) {

            // Column
            column = glyphBuf[j * font->getCharacterWidth() + i];

            if (graphicState->getColor() == GraphicalLiquidCrystal::COLOR_BLACK) {
                column = ~column;
            }

            // Streaks the column.
            glcd->streak(x + i, y, column);
        }
    }
}
