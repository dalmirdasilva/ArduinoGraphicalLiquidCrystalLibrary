/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalSimpleText.h
 * 
 * The functions to draw text in a glcd.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_SIMPLE_TEXT_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_SIMPLE_TEXT_H__ 1

#include <GraphicalLiquidCrystalText.h>
#include <GraphicalLiquidCrystal.h>
#include <GraphicalLiquidCrystalBitmapFont.h>
#include <GraphicalLiquidCrystalGraphicState.h>
#include <GraphicalLiquidCrystalPoint.h>

class GraphicalLiquidCrystalSimpleText: public GraphicalLiquidCrystalText {

public:

    /**
     * Public constructor.
     * 
     * @param                       The glcd driver.
     * @param                       The bitmap font.
     * @param                       The graphic state.
     */
    GraphicalLiquidCrystalSimpleText(GraphicalLiquidCrystal *glcd, GraphicalLiquidCrystalBitmapFont *font, GraphicalLiquidCrystalGraphicState *graphicState);

    /**
     * Prints a char at given position.
     * 
     * @param                       The x position.
     * @param                       The y position.
     * @param                       The char.
     * @param                       The size.
     * @return                      void
     */
    void printChar(unsigned char x, unsigned char y, const unsigned char c, unsigned char size);

    /**
     * Prints a char at given position.
     * 
     * @param p                     The point where the char will be printed.
     * @param c                     The char.
     * @param size                  The size of the char.
     */
    inline void printChar(GraphicalLiquidCrystalPoint *p, const unsigned char c, unsigned char size) {
        printChar(p->getX(), p->getY(), c, size);
    }
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_SIMPLE_TEXT_H__ */
