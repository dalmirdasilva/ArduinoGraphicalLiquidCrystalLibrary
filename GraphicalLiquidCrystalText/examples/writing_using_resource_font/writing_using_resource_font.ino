#include <Wire.h>
#include <Closeable.h>
#include <Seekable.h>
#include <InputStream.h>
#include <SeekableInputStream.h>
#include <ExternalEepromInputStream.h> 
#include <ResourceSeekableInputStream.h>
#include <ExternalEeprom.h>
#include <External24cl256Eeprom.h>
#include <GraphicalLiquidCrystal.h>
#include <GraphicalLiquidCrystalStraight.h>
//#include <GraphicalLiquidCrystalBuffered.h>
//#include <GraphicalLiquidCrystalSyncBuffered.h>
#include <GraphicalLiquidCrystalGraphicState.h>
#include <GraphicalLiquidCrystalDrawer.h>
#include <GraphicalLiquidCrystalShapes.h>
#include <GraphicalLiquidCrystalText.h>
#include <GraphicalLiquidCrystalSimpleText.h>
#include <GraphicalLiquidCrystalBitmapFont.h>
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
    
  GraphicalLiquidCrystalGraphicState graphicState;
  GraphicalLiquidCrystalStraight glcdDriver(A2, A3, A1, 0);
    
  glcdDriver.init(GraphicalLiquidCrystal::MODE_ON);
  glcdDriver.screen(0x80);
  graphicState.setColor(GraphicalLiquidCrystal::COLOR_WHITE);

  GraphicalLiquidCrystalBitmapFont font(&eeis);
  GraphicalLiquidCrystalText glcdText(&glcdDriver, &font, &graphicState);

  Rectangle rec(0, 10, 40, 63);
  glcdText.printString(&rec, (unsigned char*)"Lorem", 100, 1);

  rw.close();
  resourceSystem.umount();
}

void loop() {
}
