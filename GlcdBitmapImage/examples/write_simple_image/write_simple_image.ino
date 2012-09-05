#include <Wire.h>
#include <Closeable.h>
#include <OutputStream.h>
#include <ExternalEepromOutputStream.h> 
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>

unsigned char b[] = {
0x00, 0x08, 0x10
0x00, 0x30, 0x30, 0x06, 0x06, 0x30, 0x30, 0x00,
0xc0, 0x20, 0x10, 0x08, 0x08, 0x20, 0x20, 0xc0};

void setup() {
  Serial.begin(9600);
  long i;
  
  External24cl256Eeprom ee(0x50);
  ExternalEepromOutputStream eeos(&ee);

  Serial.print("Started at: ");
  Serial.println(millis());

  for (i = 0; i < sizeof(b); i++) {
    eeos.write(b[i]);
  }
  eeos.close();

  Serial.print("Finished at: ");
  Serial.println(millis());
}

void loop() {
}

