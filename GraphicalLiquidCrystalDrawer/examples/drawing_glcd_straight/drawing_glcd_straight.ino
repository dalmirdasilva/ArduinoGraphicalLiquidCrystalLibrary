#include <Wire.h>
#include <GraphicalLiquidCrystal.h>
#include <GraphicalLiquidCrystalStraight.h>
#include <GraphicalLiquidCrystalPoint.h>
#include <GraphicalLiquidCrystalRectangle.h>
#include <GraphicalLiquidCrystalGraphicState.h>
#include <GraphicalLiquidCrystalDrawer.h>

GraphicalLiquidCrystalStraight glcd;
GraphicalLiquidCrystalGraphicState graphicState;
GraphicalLiquidCrystalDrawer drawer(&glcd, &graphicState);

void setup() {
    Serial.begin(9600);
    Serial.println("Setup!");
    glcd.init(GraphicalLiquidCrystal::MODE_ON);
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
            glcd.plot(i, j, GraphicalLiquidCrystal::COLOR_WHITE);
        }
    }
    delay(5000);
}

void loop() {
    int j = 0;
    for (int i = 0; i < GLCD_WIDTH; i++) {
        glcd.plot(i, j++ % GLCD_HEIGHT, GraphicalLiquidCrystal::COLOR_WHITE);
    }
    delay(2000);
    for (int i = 0; i < GLCD_WIDTH; i++) {
        glcd.streak(i, (j-- % GLCD_HEIGHT) % 8, GraphicalLiquidCrystal::COLOR_WHITE);
    }
    delay(2000);
}