#include <Wire.h>
#include <Glcd.h>
#include <GlcdWire.h>
#include <GlcdPoint.h>
#include <GlcdRectangle.h>
#include <GlcdGraphicState.h>
#include <GlcdDrawer.h>

GlcdWire glcd(0x38);
GlcdGraphicState graphicState;
GlcdDrawer drawer(&glcd, &graphicState);

void setup() {
  glcd.init(Glcd::MODE_ON);
  glcd.screen(0xaa);
  delay(2000);
  drawer.circle(100, 50, 5);
  delay(2000);
  glcd.screen(0xff);
  delay(2000);
  glcd.screen(0x81);
  delay(2000);
  glcd.screen(0x18);
  delay(2000);
  glcd.screen(0x0f);
  delay(2000);
  glcd.screen(0xf0);
  delay(2000);
  glcd.screen(0x00);
}

void loop() {
  int j = 0;
  for (int i = 0; i < GLCD_WIDTH; i++) {
    glcd.plot(i, j++ % GLCD_HEIGHT, Glcd::COLOR_WHITE);
  }
  delay(2000);
  for (int i = 0; i < GLCD_WIDTH; i++) {
    glcd.streak(i, (j-- % GLCD_HEIGHT) % 8, Glcd::COLOR_WHITE);
  }
  delay(2000);
}