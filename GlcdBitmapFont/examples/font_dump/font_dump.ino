#include <Wire.h>
#include <Closeable.h>
#include <Seekable.h>
#include <InputStream.h>
#include <SeekableInputStream.h>
#include <ExternalEepromInputStream.h> 
#include <ExternalEepromSeekableInputStream.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>
#include <GlcdBitmapFont.h>

void dump_c(GlcdBitmapFont* font, char c) {
  long i;
  unsigned char b[font->getGlyphLength()];
  font->readGlyphData(b, c);
  Serial.print(c, HEX);
  Serial.print("(");
  Serial.print(c);
  Serial.print("): ");
  for (i = 0; i < font->getGlyphLength() - 1; i++) {
    Serial.print("0x");
    Serial.print(b[i], HEX);
    Serial.print(", ");
  }
  Serial.print("0x");
  Serial.println(b[i], HEX);
}

void setup() {
  int seq;
  Serial.begin(9600);
  
  Serial.println("Continue? (y?)");
  while(Serial.read() != 'y');
  
  External24cl256Eeprom ee(0x50);
  ExternalEepromSeekableInputStream eeis(&ee);
  
  GlcdBitmapFont font(&eeis);

  Serial.print("Started at: ");
  Serial.println(millis());

  Serial.print("Font info: ");
  Serial.println(font.getInfo());
  Serial.print("Font character width: ");
  Serial.println(font.getCharacterWidth());
  Serial.print("Font character height: ");
  Serial.println(font.getCharacterHeight());
  Serial.print("Font sequence count: ");
  Serial.println(font.getSequenceCount());

  for (seq = 0; seq < font.getSequenceCount(); seq++) {
    unsigned char first, last;
    eeis.seek(4+(4*seq));
    first = eeis.read();
    last = eeis.read();
    Serial.print("\nSequence: ");
    Serial.print(seq);
    Serial.print(", first char: ");
    Serial.print(first, HEX);
    Serial.print(", last char: ");
    Serial.println(last, HEX);
    for (unsigned char c = first; c <= last; c++) {
      dump_c(&font, c);
    }
  }
  
  eeis.close();
  Serial.print("Finished at: ");
  Serial.println(millis());
}

void loop() {
}
