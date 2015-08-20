/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalRectangle.h
 * 
 * A GraphicalLiquidCrystalRectangle is rectangle in the glcd screen.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_RECTANGLE_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_RECTANGLE_H__ 1

class GraphicalLiquidCrystalRectangle {
private:

    /**
     * The left position
     */
    unsigned char left;

    /**
     * The top position
     */
    unsigned char top;

    /**
     * The right position
     */
    unsigned char right;

    /**
     * The bottom position
     */
    unsigned char bottom;

public:

    /**
     * Public constructor
     */
    GraphicalLiquidCrystalRectangle();

    /**
     * Public constructor
     * 
     * @param left      The left position
     * @param top       The top position
     * @param right     The right position
     * @param bottom    The bottom position
     */
    GraphicalLiquidCrystalRectangle(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom);

    /**
     * Sets the top position
     * 
     * @param top       The top position
     */
    void setTop(unsigned char top);

    /**
     * Gets the top position
     * 
     * @return          The top position
     */
    unsigned char getTop();

    /**
     * Sets the left position
     * 
     * @param left      The left position
     */
    void setLeft(unsigned char left);

    /**
     * Gets the top position
     * 
     * @return          The top position
     */
    unsigned char getLeft();

    /**
     * Sets the right position
     * 
     * @param right     The right position
     */
    void setRight(unsigned char right);

    /**
     * Gets the right position
     * 
     * @return          The right position
     */
    unsigned char getRight();

    /**
     * Sets the bottom position
     * 
     * @param bottom    The bottom position
     */
    void setBottom(unsigned char bottom);

    /**
     * Gets the top position
     * 
     * @return          The bottom position
     */
    unsigned char getBottom();

    /**
     * Gets the width of the image
     * 
     * @return          The width
     */
    unsigned char getWidth();

    /**
     * Gets the height of the image
     * 
     * @return          The height
     */
    unsigned char getHeight();

    /**
     * Gets the area of the image
     * 
     * @return          The area
     */
    unsigned int getArea();
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_RECTANGLE_H__ */
