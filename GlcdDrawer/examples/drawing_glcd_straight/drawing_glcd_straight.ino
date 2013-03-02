#include <Wire.h>
#include <Glcd.h>
#include <GlcdStraight.h>
#include <GlcdPoint.h>
#include <GlcdRectangle.h>
#include <GlcdGraphicState.h>
#include <GlcdDrawer.h>

GlcdStraight glcd;
GlcdGraphicState graphicState;
GlcdDrawer drawer(&glcd, &graphicState);

void setup() {
    Serial.begin(9600);
    Serial.println("Setup!");
    glcd.init(Glcd::MODE_ON);
    glcd.screen(0xff);
    delay(2000);
    drawer.drawCircle(100, 50, 5);
    delay(2000);
    drawer.drawCircle(10, 50, 10);
    delay(2000);
    drawer.drawCircle(30, 10, 4);
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
    for (int i = 0; i < glcd.getWidth(); i++) {
        for (int j = 0; j < glcd.getHeight(); j++) {
            glcd.plot(i, j, Glcd::COLOR_WHITE);
        }
    }
    delay(5000);
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