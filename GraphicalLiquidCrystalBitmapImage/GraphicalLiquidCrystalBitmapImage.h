/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalBitmapImage.h
 * 
 * The representation of a GLCD image.
 * 
 * The first three bytes specify the image's information and dimensions; 
 * 'info', 'width' and 'height' respectively;
 * 
 * The rest of the data have the content of the image;
 * 
 * The minimum size of an image is 1x8; this hypothetical image has 4 
 * bytes, as follow: 
 * 
 * <pre>
 * 0x00, 0x01, 0x08, 0xXX
 *  |     |     |     |___ Image content
 *  |     |     |_________ Height
 *  |     |_______________ Width
 *  |_____________________ Info
 * </pre>
 * 
 * The contents of the image is organized to take advantage of the 
 * structure of the display, the display is divided into pages, each 
 * page has a number of bytes, these bytes are arranged horizontally, 
 * forming a chain of 8-bit high.
 * 
 * File structure
 * 
 * Header organization:
 * 
 * <pre>
 * +-------------------------+
 * |      Image info         | 0b00000000
 * +-------------------------+
 * |  Image width (in bits)  | 0b00000000
 * +-------------------------+
 * |  Image height (in bits) | 0b00000000
 * +-------------------------+
 * |                         | 0b00000000
 * |       IMAGE DATA        | 0b00000000
 * |     ARRAY OF BYTES      | 0b00000000
 * |                         | 0b00000000
 * +-------------------------+
 * </pre>
 * 
 * Image info organization:
 * 
 * <pre>
 * +-------------------------+
 * |      Image info         | 0b00000000
 * +-------------------------+   ||||||||__ Image type (magic number)
 *                               |||||||___ Image type (magic number)
 *                               ||||||____
 *                               |||||_____
 *                               ||||______
 *                               |||_______
 *                               ||________
 *                               |_________
 *                               
 * |  Image width (in bits)  | 0b00000000 _ 8 bits to represent the width
 * +-------------------------+
 * |  Image height (in bits) | 0b00000000 _ 8 bits to represent the height
 * </pre>
 * 
 * Image data organization:
 * 
 * <pre>
 *           L    L
 *           i    i
 *           n    n
 *           e    e
 *           0    1    ...
 *         +--------------------------------------------------------------+
 *         | b7 | b7 |
 *         | b6 | b6 |
 *         | b5 | b5 |
 * page 0  | b4 | b4 |
 *         | b3 | b3 |
 *         | b2 | b2 |
 *         | b1 | b1 |
 *         | b0 | b0 |
 *         +--------------------------------------------------------------+
 *         |
 *         |
 * page 1  |
 *         
 * 
 * ...
 * x
 * </pre>
 * 
 * Image example
 * 
 * Here is an example of an image with 8x16 (smile face):
 * 
 * <pre>
 * 0x00, 0x08, 0x10,
 * 0x00, 0x30, 0x30, 0x06, 0x06, 0x30, 0x30, 0x00,
 * 0xc0, 0x20, 0x10, 0x08, 0x08, 0x20, 0x20, 0xc0
 * </pre>
 * 
 * Here is the same image organized as will be printed into the glcd,
 * 
 * <pre>
 * +-+-+-+-+-+-+-+-+
 * |0|0|0|0|0|0|0|0| -> the MSB
 * |0|0|0|0|0|0|0|0|
 * |0|1|1|0|0|1|1|0|
 * |0|1|1|0|0|1|1|0|
 * |0|0|0|0|0|0|0|0|
 * |0|0|0|1|1|0|0|0|
 * |0|0|0|1|1|0|0|0|
 * |0|0|0|0|0|0|0|0| -> the LSB
 * +-+-+-+-+-+-+-+-+
 * |1|0|0|0|0|0|0|1| -> the MSB
 * |1|0|0|0|0|0|0|1|
 * |0|1|0|0|0|0|1|0|
 * |0|0|1|0|0|1|0|0|
 * |0|0|0|1|1|0|0|0|
 * |0|0|0|0|0|0|0|0|
 * |0|0|0|0|0|0|0|0|
 * |0|0|0|0|0|0|0|0| -> the LSB
 * +-+-+-+-+-+-+-+-+
 * </pre>
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_IMAGE_H__
#define __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_IMAGE_H__ 1

#include <SeekableInputStream.h>

class GraphicalLiquidCrystalBitmapImage {

protected:
    
    /**
     * Image header.
     */
    struct Header {
        unsigned char info;
        unsigned char width;
        unsigned char height;
    };
    Header header;

    /**
     * Input stream which font data comes from.
     */
    SeekableInputStream* inputStream;
    
    /**
     * Data offset. It is the position when the header ends.
     */
    unsigned int dataOffset;
    
public:

    /**
     * Public constructor.
     * 
     * @param inputStream       The associated input stream.
     */
    GraphicalLiquidCrystalBitmapImage(SeekableInputStream* inputStream);

    /**
     * Gets the info of an image.
     * 
     * @return                  The image info entry.
     */
    unsigned char getInfo();

    /**
     * Gets the width of an image.
     * 
     * @return                  The image width.
     */
    unsigned char getWidth();

    /**
     * Gets the height of an image.
     * 
     * @return                  The image height.
     */
    unsigned char getHeight();

    /**
     * Reads a pixel from the image.
     * 
     * @param x                 The x position.
     * @param y                 The y position.
     * @return                  The pixel.
     */
    bool getPixel(unsigned char x, unsigned char y);

    /**
     * Reads a column from the image.
     * 
     * @param buf               The buffer to be filled with the column data.
     * @param col               The column.
     */
    void readColumn(unsigned char* buf, unsigned char col);

    /**
     * Reads a row from the image.
     * 
     * This will reads a row with 8 bits of height.
     * 
     * @param buf               The buffer to be filled with the column data.
     * @param row               The row.
     */
    void readRow(unsigned char* buf, unsigned char row);
};

#endif /* __ARDUINO_LIBRARY_GRAPHICAL_LIQUID_CRYSTAL_BITMAP_IMAGE_H__ */
