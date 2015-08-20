/**
 * Arduino Graphic Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalBitmapFont.cpp
 * 
 * The representation of a glcd font.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalBitmapFont.h"
#include <SeekableInputStream.h>

GraphicalLiquidCrystalBitmapFont::GraphicalLiquidCrystalBitmapFont(SeekableInputStream* inputStream) : inputStream(inputStream) {
    dataOffset = sizeof (Header);
    inputStream->seek(0);
    header.info = inputStream->read();
    header.characterWidth = inputStream->read();
    header.characterHeight = inputStream->read();
    header.sequenceCount = inputStream->read();
    glyphLength = header.characterWidth * (header.characterHeight / 8);
}

unsigned char GraphicalLiquidCrystalBitmapFont::getInfo() {
    return header.info;
}

unsigned char GraphicalLiquidCrystalBitmapFont::getCharacterWidth() {
    return header.characterWidth;
}

unsigned char GraphicalLiquidCrystalBitmapFont::getCharacterHeight() {
    return header.characterHeight;
}

unsigned char GraphicalLiquidCrystalBitmapFont::getSequenceCount() {
    return header.sequenceCount;
}

unsigned char GraphicalLiquidCrystalBitmapFont::getGlyphLength() {
    return glyphLength;
}

unsigned char GraphicalLiquidCrystalBitmapFont::readGlyphData(unsigned char *buf, char c) {
    unsigned int offset = getGlyphOffset(c);
    if (offset == 0) {
        return 0;
    }
    inputStream->seek(offset);
    return (unsigned char) inputStream->read(buf, 0, getGlyphLength());
}

unsigned int GraphicalLiquidCrystalBitmapFont::getGlyphOffset(char c) {
    unsigned char i, first, last;
    unsigned int offset = 0;
    inputStream->seek(dataOffset);
    for (i = 0; i < getSequenceCount(); i++) {
        first = inputStream->read();
        last = inputStream->read();
        if (c >= first && c <= last) {
            offset = inputStream->read();
            offset <<= 8;
            offset |= inputStream->read();
            offset += (c - first) * getGlyphLength();
            break;
        } else {
            inputStream->skip(2);
        }
    }
    return offset;
}
