/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalPoint.h
 * 
 * A point is pixel in the glcd screen. Point has a x and y positions.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_POINT_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_POINT_H__ 1

class GraphicalLiquidCrystalPoint {
private:

    /**
     * The x position
     */
    unsigned char x;

    /**
     * The y position
     */
    unsigned char y;
public:

    /**
     * Public constructor
     */
    GraphicalLiquidCrystalPoint();

    /**
     * Public constructor
     * 
     * @param x         The x position
     * @param y         The y position
     */
    GraphicalLiquidCrystalPoint(unsigned char x, unsigned char y);

    /**
     * Sets x position
     * 
     * @param top       The x position
     */
    void setX(unsigned char top);

    /**
     * Gets x position
     * 
     * @return          The x position
     */
    unsigned char getX();

    /**
     * Sets the y position
     * 
     * @param left      The y position
     */
    void setY(unsigned char left);

    /**
     * Gets position y
     * 
     * @return          The y position
     */
    unsigned char getY();
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_POINT_H__ */
