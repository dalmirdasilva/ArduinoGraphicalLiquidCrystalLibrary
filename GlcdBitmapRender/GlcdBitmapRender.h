/**
 * Arduino Graphic LCD Library
 * 
 * GlcdBitmapRender.h
 * 
 * The header functions to draw bitmaps in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_H__
#define __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_H__ 1

#include <Glcd.h>
#include <GlcdPoint.h>
#include <GlcdBitmapImage.h>

class GlcdBitmapRender {
protected:

    /**
     * Glcd driver to render.
     */
    Glcd *glcd;

public:

    /**
     * Public constructor.
     * 
     * @param glcd      The glcd driver instance.
     */
    GlcdBitmapRender(Glcd *glcd);

    /**
     * Draws an image at given x, y position.
     * 
     * @param image     The image to be drawn.
     * @param x         The x position.
     * @param y         The y position.
     */
    void drawImage(GlcdBitmapImage *image, unsigned char x, unsigned char y);

    /**
     * Draws an image at given point.
     * 
     * @param image     The image to be drawn. 
     * @param p         The point.
     */
    inline void drawImage(GlcdBitmapImage *image, GlcdPoint *p) {
        drawImage(image, p->getX(), p->getY());
    }

    /**
     * Draws an image at the row.
     * 
     * @param image     The image to be drawn.
     * @param x         The x position.
     * @param row       The row.
     */
    void drawImageAtRow(GlcdBitmapImage *image, unsigned char x, unsigned char row);
};

#endif /* __ARDUINO_LIBRARY_GLCD_BITMAP_DRAWER_H__ */
