#include <Wire.h>
#include <Closeable.h>
#include <Seekable.h>
#include <InputStream.h>
#include <SeekableInputStream.h>
#include <ExternalEepromInputStream.h> 
#include <ExternalEepromSeekableInputStream.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>
#include <GlcdBitmapImage.h>

void setup() {
  Serial.begin(9600);
  long i;
  
  External24cl256Eeprom ee(0x50);
  ExternalEepromSeekableInputStream eeis(&ee);
  
  GlcdBitmapImage img(&eeis);

  Serial.print("Started at: ");
  Serial.println(millis());

  Serial.print("info: ");
  Serial.println(img.getInfo());
  Serial.print("getWidth: ");
  Serial.println(img.getWidth());
  Serial.print("getHeight: ");
  Serial.println(img.getHeight());

  unsigned char b[img.getHeigh()];
  img.readColumn(b, 0);
  
  for (i = 0; i < img.getWidth(); i++) {
    Serial.println(b[i], HEX);
  }

  eeis.close();
  Serial.print("Finished at: ");
  Serial.println(millis());
}

void loop() {
}
