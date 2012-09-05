#include <Wire.h>
#include <Closeable.h>
#include <Seekable.h>
#include <InputStream.h>
#include <SeekableInputStream.h>
#include <ExternalEepromInputStream.h> 
#include <ResourceSeekableInputStream.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>
#include <Glcd.h>
#include <GlcdStraight.h>
//#include <GlcdBuffered.h>
//#include <GlcdSyncBuffered.h>
#include <GlcdGraphicState.h>
#include <GlcdDrawer.h>
#include <GlcdShapes.h>
#include <GlcdText.h>
#include <GlcdSimpleText.h>
#include <GlcdBitmapFont.h>
#include <rs.h>
#include <rs_util.h>
#include <rs_io.h>
#include <rs_init_partition.h>
#include <Resource.h>
#include <ResourceIO.h>
#include <ResourceSystem.h>
#include <SimpleResource.h>
#include <SimpleResourceIO.h>
#include <SimpleResourceSystem.h>
#include <SimpleExternalEepromResourceIO.h>
#include <InputStream.h>
#include <ResourceInputStream.h>
#include <OutputStream.h>
#include <Seekable.h>
#include <Closeable.h>
#include <InputStream.h>
#include <ResourceInputStream.h>

void setup() {
  Serial.begin(9600);

  Serial.println("Sure? (y/n)");
  while (!Serial.available());
  while (Serial.read() != 'y');

  SimpleResourceSystem resourceSystem(RS_DRIVER_ARDUINO_EEPROM);
  External24cl256Eeprom ee(0x50);
  SimpleExternalEepromResourceIO io(&ee);
  SimpleResourceIO::associateIO(&io, RS_DRIVER_ARDUINO_EEPROM);
    
  resourceSystem.mount(ResourceSystem::MOUNT_READ_ONLY);
    
  SimpleResource rw = resourceSystem.getResourceByCode(4);
  rw.open(Resource::OPEN_READ_ONLY);
  ResourceSeekableInputStream eeis(&rw);
  
  while (eeis.available()) {
    Serial.println(eeis.read(), HEX);
  }
    
  GlcdGraphicState graphicState;
  GlcdStraight glcdDriver(A2, A3, A1, 0);
    
  glcdDriver.init(Glcd::MODE_ON);
  glcdDriver.screen(0x80);
  graphicState.setColor(Glcd::COLOR_WHITE);

  GlcdBitmapFont font(&eeis);
  GlcdText glcdText(&glcdDriver, &font, &graphicState);

  Rectangle rec(0, 10, 40, 63);
  glcdText.printString(&rec, (unsigned char*)"Lorem", 100, 1);

  rw.close();
  resourceSystem.umount();
}

void loop() {
}
