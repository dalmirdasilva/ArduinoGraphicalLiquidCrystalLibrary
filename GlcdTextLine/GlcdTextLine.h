/**
 * Arduino Graphic LCD Library
 * 
 * GlcdTextLine.h
 * 
 * The header functions to draw text in a glcd always at the same line.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_TEXT_LINE_H__
#define __ARDUINO_LIBRARY_GLCD_TEXT_LINE_H__ 1

#include <Glcd.h>
#include <GlcdRectangle.h>
#include <GlcdDrawer.h>

class GlcdTextLine {
protected:

    /**
     * The glcd text
     */
    GlcdText *glcdText;

    /**
     * The glcd drawer
     */
    GlcdDrawer *glcdDrawer;

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
    GlcdTextLine(GlcdText *glcdText, GlcdDrawer *glcdDrawer, unsigned char y);

    /**
     * Prints lines.
     * 
     * @param text                  The text to be printed.
     * @param count                 void
     */
    void printLines(const unsigned char *text, int count);
};

#endif /* __ARDUINO_LIBRARY_GLCD_TEXT_LINE_H__ */
