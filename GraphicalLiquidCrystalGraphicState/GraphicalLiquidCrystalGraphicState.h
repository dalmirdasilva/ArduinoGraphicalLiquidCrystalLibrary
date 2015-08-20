/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalGraphicState.h
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_GRAPHIC_STATE_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_GRAPHIC_STATE_H__ 1

#include <GraphicalLiquidCrystal.h>

/**
 * GraphicalLiquidCrystalGraphicState provides the information
 * about the current state of how to print things into the
 * module.
 */
class GraphicalLiquidCrystalGraphicState {

public:

    enum LinePattern {
        SOLID_LINE = 0,
        DOTED_LINE = 1
    };

    enum FillPattern {
        SOLID_FILL = 0,
        DOTED_FILL = 1
    };

    /**
     * The line pattern.
     */
    LinePattern linePattern;

    /**
     * The fill pattern.
     */
    FillPattern fillPattern;

    /**
     * The color instance.
     */
    GraphicalLiquidCrystal::Color color;

    /**
     * The number of leading pixels (space between lines).
     */
    unsigned char leading;

    /**
     * The number of space pixels (space between words).
     */
    unsigned char space;

    /**
     * If the shapes need to be filled.
     */
    bool fill;

    /**
     * Public constructor.
     */
    GraphicalLiquidCrystalGraphicState();

    /**
     * Sets fill pattern.
     * 
     * @param fillPattern       The fill pattern instance.
     */
    void setFillPattern(FillPattern fillPattern);

    /**
     * Gets the fill pattern.
     * 
     * @return                  The fill pattern instance.
     */
    FillPattern getFillPattern();

    /**
     * Sets the lone pattern.
     * 
     * @param linePattern       The line pattern instance.
     */
    void setLinePattern(LinePattern linePattern);

    /**
     * Gets the line pattern.
     * 
     * @return                  The line pattern.
     */
    LinePattern getLinePattern();

    /**
     * Sets the leading value.
     * 
     * @param leading           The next leading value.
     */
    void setLeading(unsigned char leading);

    /**
     * Gets the leading value.
     * 
     * @return                  The current leading value.
     */
    unsigned char getLeading();

    /**
     * Sets the color.
     * 
     * @param color             The next used color.
     */
    void setColor(GraphicalLiquidCrystal::Color color);

    /**
     * Gets the used color.
     * 
     * @return                  The current used color.
     */
    GraphicalLiquidCrystal::Color getColor();

    /**
     * Inverts the current color.
     */
    void invertColor();

    /**
     * Sets the space value.
     * 
     * @param space             The next space value.
     */
    void setSpace(unsigned char space);

    /**
     * Gets the space value.
     * 
     * @return                  The current space value.
     */
    unsigned char getSpace();

    /**
     * Sets the fill flag.
     * 
     * @param fill              The fill flag.
     */
    void setFill(bool fill);

    /**
     * Gets the fill flag.
     * 
     * @return                  The current fill flag.
     */
    bool getFill();
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_GRAPHIC_STATE_H__ */
