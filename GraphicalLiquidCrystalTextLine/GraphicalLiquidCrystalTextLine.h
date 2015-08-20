/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalTextLine.h
 * 
 * The header functions to draw text in a glcd always at the same line.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_TEXT_LINE_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_TEXT_LINE_H__ 1

#include <GraphicalLiquidCrystal.h>
#include <GraphicalLiquidCrystalText.h>
#include <GraphicalLiquidCrystalDrawer.h>

class GraphicalLiquidCrystalTextLine {

protected:

    /**
     * The glcd text
     */
    GraphicalLiquidCrystalText *glcdText;

    /**
     * The glcd drawer
     */
    GraphicalLiquidCrystalDrawer *glcdDrawer;

    /**
     * The y position.
     */
    unsigned char y;

public:

    /**
     * Public constructor.
     * @param glcdText              The glcd text instance.
     * @param glcdDrawer            The glcd drawer instance.
     * @param y                     The y position.
     */
    GraphicalLiquidCrystalTextLine(GraphicalLiquidCrystalText *glcdText, GraphicalLiquidCrystalDrawer *glcdDrawer, unsigned char y);

    /**
     * Prints lines.
     * 
     * @param text                  The text to be printed.
     * @param count                 void
     */
    void printLines(const unsigned char *text, unsigned char count);
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_TEXT_LINE_H__ */
