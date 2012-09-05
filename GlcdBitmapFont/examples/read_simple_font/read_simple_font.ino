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

void setup() {
  Serial.begin(9600);
  long i;
  
  External24cl256Eeprom ee(0x50);
  ExternalEepromSeekableInputStream eeis(&ee);
  
  GlcdBitmapFont glcd(&eeis);
  unsigned char b[glcd.getGlyphLength()];

  Serial.print("Started at: ");
  Serial.println(millis());

  Serial.print("info: ");
  Serial.println(glcd.getInfo());
  Serial.print("characterWidth: ");
  Serial.println(glcd.getCharacterWidth());
  Serial.print("characterHeight: ");
  Serial.println(glcd.getCharacterHeight());
  Serial.print("sequenceCount: ");
  Serial.println(glcd.getSequenceCount());

  glcd.readGlyphData(b, 48);
  
  for (i = 0; i < glcd.getGlyphLength(); i++) {
    Serial.println(b[i], 10);
  }

  eeis.close();
  Serial.print("Finished at: ");
  Serial.println(millis());
}

void loop() {
}
