/**
 * Arduino Graphic LCD Library
 * 
 * GlcdSimpleText.h
 * 
 * The functions to draw text in a glcd.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_SIMPLE_TEXT_H__
#define __ARDUINO_LIBRARY_GLCD_SIMPLE_TEXT_H__ 1

#include <Glcd.h>
#include <GlcdText.h>
#include <GlcdBitmapFont.h>
#include <GlcdGraphicState.h>

class GlcdSimpleText : public GlcdText {
public:

    /**
     * Public constructor.
     * 
     * @param                       The glcd driver.
     * @param                       The bitmap font.
     * @param                       The graphic state.
     */
    GlcdSimpleText(Glcd *glcd, GlcdBitmapFont *font, GlcdGraphicState *graphicState);

    /**
     * Prints a char at given position.
     * 
     * @param                       The x position.
     * @param                       The y position.
     * @param                       The char.
     * @param                       The size.
     * @return                      void
     */
    virtual void printChar(unsigned char x, unsigned char y, const unsigned char c, unsigned char size);
    
    /**
     * Prints a char at given position.
     * 
     * @param p                     The point where the char will be printed.
     * @param c                     The char.
     * @param size                  The size of the char.
     */
    inline void printChar(GlcdPoint *p, const unsigned char c, unsigned char size) {
        printChar(p->getX(), p->getY(), c, size);
    }
};

#endif /* __SDCC_LIBRARY_GLCD_SIMPLE_TEXT_H__ */
