/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalDrawer.h
 * 
 * The header functions to draw in the module.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_DRAWER_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_DRAWER_H__ 1

#include <GraphicalLiquidCrystalGraphicState.h>
#include <GraphicalLiquidCrystalPoint.h>
#include <GraphicalLiquidCrystalRectangle.h>
#include <GraphicalLiquidCrystal.h>

class GraphicalLiquidCrystalDrawer {

private:

    /**
     * The driver instance.
     */
    GraphicalLiquidCrystal *glcd;

    /**
     * The graphic state instance.
     */
    GraphicalLiquidCrystalGraphicState *graphicState;

public:

    /**
     * Public constructor.
     * 
     * @param glcd              The driver instance.
     * @param graphicState      The graphic state instance.
     */
    GraphicalLiquidCrystalDrawer(GraphicalLiquidCrystal *glcd, GraphicalLiquidCrystalGraphicState *graphicState);

    /**
     * Sets the driver instance.
     * 
     * @param glcd              The driver instance.
     */
    void setGraphicalLiquidCrystal(GraphicalLiquidCrystal *glcd);

    /**
     * Sets the graphic state instance.
     * 
     * @param graphicState      The graphic state instance.
     */
    void setGraphicState(GraphicalLiquidCrystalGraphicState *graphicState);

    /**
     * Gets the driver instance.
     * 
     * @return                  The driver instance.
     */
    GraphicalLiquidCrystal *getGraphicalLiquidCrystal();

    /**
     * Gets the graphic state instance.
     * 
     * @return                  The graphic state instance.
     */
    GraphicalLiquidCrystalGraphicState *getGraphicState();

    /**
     * Drawers a line in the glcd plane.
     * 
     * @param x1                The x axis for the left of the rectangle.
     * @param y1                The x axis for the right of the rectangle.
     * @param x2                The y axis for the bottom of the rectangle.
     * @param y2                The y axis for the top of the rectangle.
     */
    void drawLine(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

    /**
     * Drawers a line in the glcd plane.
     * 
     * @param p1                The point 1.
     * @param p2                The point 2.
     */
    inline void drawLine(GraphicalLiquidCrystalPoint *p1, GraphicalLiquidCrystalPoint *p2) {
        drawLine(p1->getX(), p1->getY(), p2->getX(), p2->getY());
    }

    /**
     * Drawers a rectangle on the glcd plane.
     * 
     * @param x1                The x axis for the left of the rectangle.
     * @param y1                The x axis for the right of the rectangle.
     * @param x2                The y axis for the bottom of the rectangle.
     * @param y2                The y axis for the top of the rectangle.
     */
    void drawRectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);

    /**
     * Drawers a rectangle on the glcd plane.
     * 
     * @param r                 The rectangle.
     */
    inline void drawRectangle(GraphicalLiquidCrystalRectangle *r) {
        drawRectangle(r->getLeft(), r->getTop(), r->getRight(), r->getBottom());
    }

    /**
     * Drawers a circle in the glcd plane.
     * 
     * @param x                 The coordinate x.
     * @param y                 The coordinate y.
     * @param radius            The radius.
     */
    void drawCircle(unsigned char x, unsigned char y, unsigned char radius);

    /**
     * Drawers a circle in the glcd plane.
     * 
     * @param p
     * @param radius
     */
    inline void drawCircle(GraphicalLiquidCrystalPoint *p, unsigned char radius) {
        drawCircle(p->getX(), p->getY(), radius);
    }
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_DRAWER_H__ */
