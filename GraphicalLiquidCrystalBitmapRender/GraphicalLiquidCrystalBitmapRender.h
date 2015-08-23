/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalBitmapRender.h
 * 
 * The header functions to draw bitmaps in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_DRAWER_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_DRAWER_H__ 1

#include <GraphicalLiquidCrystalBitmapImage.h>
#include <GraphicalLiquidCrystalPoint.h>
#include <GraphicalLiquidCrystal.h>

class GraphicalLiquidCrystalBitmapRender {

protected:

    /**
     * GraphicalLiquidCrystal driver to render.
     */
    GraphicalLiquidCrystal *glcd;

public:

    /**
     * Public constructor.
     * 
     * @param glcd      The GRAPHICAL_LIQUID_CRYSTAL driver instance.
     */
    GraphicalLiquidCrystalBitmapRender(GraphicalLiquidCrystal *glcd);

    /**
     * Draws an image at given x, y position.
     * 
     * @param image     The image to be drawn.
     * @param x         The x position.
     * @param y         The y position.
     */
    void drawImage(GraphicalLiquidCrystalBitmapImage *image, unsigned char x, unsigned char y);

    /**
     * Draws an image at given point.
     * 
     * @param image     The image to be drawn. 
     * @param p         The point.
     */
    inline void drawImage(GraphicalLiquidCrystalBitmapImage *image, GraphicalLiquidCrystalPoint *p) {
        drawImage(image, p->getX(), p->getY());
    }

    /**
     * Draws an image at the row.
     * 
     * @param image     The image to be drawn.
     * @param x         The x position.
     * @param row       The row.
     */
    void drawImageAtRow(GraphicalLiquidCrystalBitmapImage *image, unsigned char x, unsigned char row);
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_DRAWER_H__ */
