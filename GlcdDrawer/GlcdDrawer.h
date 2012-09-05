/**
 * Arduino Graphic LCD Library
 * 
 * GlcdDrawer.h
 * 
 * The header functions to draw in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_DRAWER_H__
#define __ARDUINO_LIBRARY_GLCD_DRAWER_H__ 1

#include <Glcd.h>
#include <GlcdGraphicState.h>
#include <GlcdPoint.h>
#include <GlcdRectangle.h>

class GlcdDrawer {
private:

    /**
     * The driver instance.
     */
    Glcd *glcd;

    /**
     * The graphic state instance.
     */
    GlcdGraphicState *graphicState;

public:

    /**
     * Public constructor.
     * 
     * @param glcd              The driver instance.
     * @param graphicState      The graphic state instance.
     */
    GlcdDrawer(Glcd *glcd, GlcdGraphicState *graphicState);

    /**
     * Sets the driver instance.
     * 
     * @param glcd              The driver instance.
     */
    void setGlcd(Glcd *glcd);

    /**
     * Sets the graphic state instance.
     * 
     * @param graphicState      The graphic state instance.
     */
    void setGraphicState(GlcdGraphicState *graphicState);

    /**
     * Gets the driver instance.
     * 
     * @return                  The driver instance.
     */
    Glcd *getGlcd();

    /**
     * Gets the graphic state instance.
     * 
     * @return                  The graphic state instance.
     */
    GlcdGraphicState *getGraphicState();

    /**
     * Drawers a line in the glcd plane.
     * 
     * @param x1                The x axis for the left of the rectangle.
     * @param y1                The x axis for the right of the rectangle.
     * @param x2                The y axis for the bottom of the rectangle.
     * @param y2                The y axis for the top of the rectangle.
     */
    void line(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
    
    /**
     * Drawers a line in the glcd plane.
     * 
     * @param p1                The point 1.
     * @param p2                The point 2.
     */
    inline void line(GlcdPoint *p1, GlcdPoint *p2) {
        line(p1->getX(), p1->getY(), p2->getX(), p2->getY());
    }

    /**
     * Drawers a rectangle on the glcd plane.
     * 
     * @param x1                The x axis for the left of the rectangle.
     * @param y1                The x axis for the right of the rectangle.
     * @param x2                The y axis for the bottom of the rectangle.
     * @param y2                The y axis for the top of the rectangle.
     */
    void rect(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2);
    
    /**
     * Drawers a rectangle on the glcd plane.
     * 
     * @param r                 The rectangle.
     */
    inline void rect(GlcdRectangle *r) {
        rect(r->getLeft(), r->getTop(), r->getRight(), r->getBottom());
    }

    /**
     * Drawers a circle in the glcd plane.
     * 
     * @param x                 The coordinate x.
     * @param y                 The coordinate y.
     * @param radius            The radius.
     */
    void circle(unsigned char x, unsigned char y, unsigned char radius);
    
    /**
     * Drawers a circle in the glcd plane.
     * 
     * @param p
     * @param radius
     */
    inline void circle(GlcdPoint *p, unsigned char radius) {
        circle(p->getX(), p->getY(), radius);
    }
};

#endif /* __ARDUINO_LIBRARY_GLCD_DRAWER_H__ */
