#include <Wire.h>
#include <Closeable.h>
#include <OutputStream.h>
#include <ExternalEepromOutputStream.h> 
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>

unsigned char b[] = {
  0, 5, 8, 2, 32, 33, 0,12,48, 49, 0,22, 0,0,0,0,0, 0,0,0xff,0,0, 0,5,6,0,0, 4,0,0,7,8
};

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
