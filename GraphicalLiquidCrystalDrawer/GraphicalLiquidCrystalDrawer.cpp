/**
 * Arduino Graphical Liquid Crystal Library
 * 
 * GraphicalLiquidCrystalDrawer.cpp
 * 
 * The header functions to draw in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#include "GraphicalLiquidCrystalDrawer.h"
#include <Arduino.h>

GraphicalLiquidCrystalDrawer::GraphicalLiquidCrystalDrawer(GraphicalLiquidCrystal *glcd, GraphicalLiquidCrystalGraphicState *graphicState)
        : glcd(glcd), graphicState(graphicState) {
}

void GraphicalLiquidCrystalDrawer::setGraphicalLiquidCrystal(GraphicalLiquidCrystal *glcd) {
    this->glcd = glcd;
}

void GraphicalLiquidCrystalDrawer::setGraphicState(GraphicalLiquidCrystalGraphicState *graphicState) {
    this->graphicState = graphicState;
}

GraphicalLiquidCrystal *GraphicalLiquidCrystalDrawer::getGraphicalLiquidCrystal() {
    return glcd;
}

GraphicalLiquidCrystalGraphicState *GraphicalLiquidCrystalDrawer::getGraphicState() {
    return graphicState;
}

void GraphicalLiquidCrystalDrawer::drawLine(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {
    unsigned char dx, dy;
    char sx, sy;
    int P, P0;
    if (x2 > x1) {
        dx = x2 - x1;
        sx = 1;
    } else {
        dx = x1 - x2;
        sx = -1;
    }
    if (y2 > y1) {
        dy = y2 - y1;
        sy = 1;
    } else {
        dy = y1 - y2;
        sy = -1;
    }
    P = (dx > dy ? dx : -dy) / 2;
    while (1) {
        glcd->plot(x1, y1, graphicState->getColor());
        if (x1 == x2 && y1 == y2) {
            break;
        }
        P0 = P;
        if (P0 > -dx) {
            P -= dy;
            x1 += sx;
        }
        if (P0 < dy) {
            P += dx;
            y1 += sy;
        }
    }
}

void GraphicalLiquidCrystalDrawer::drawRectangle(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {

    if (graphicState->getFill()) {

        // Find the y min and max
        unsigned char yMin, yMax;

        if (y1 < y2) {
            yMin = y1;
            yMax = y2;
        } else {
            yMin = y2;
            yMax = y1;
        }

        // Drawer lines to fill the rectangle
        for (; yMin <= yMax; yMin++) {
            drawLine(x1, yMin, x2, yMin);
        }
    } else {

        // Drawer the 4 sides
        drawLine(x1, y1, x2, y1);
        drawLine(x1, y2, x2, y2);
        drawLine(x1, y1, x1, y2);
        drawLine(x2, y1, x2, y2);
    }
}

void GraphicalLiquidCrystalDrawer::drawCircle(unsigned char x, unsigned char y, unsigned char radius) {

    int P = 1 - radius;
    unsigned char a = 0;
    unsigned char b = radius;

    // To fit the GLCS screen
    if (x < radius) {
        x = radius;
    } else if ((glcd->getWidth() - 1 - x) < radius) {
        x = glcd->getWidth() - 1 - radius;
    }
    if (y < radius) {
        y = radius;
    } else if ((glcd->getHeight() - 1 - y) < radius) {
        y = glcd->getHeight() - 1 - radius;
    }
    do {
        if (graphicState->getFill()) {

            // Fill
            drawLine(x - a, y + b, x + a, y + b);
            drawLine(x - a, y - b, x + a, y - b);
            drawLine(x - b, y + a, x + b, y + a);
            drawLine(x - b, y - a, x + b, y - a);

        } else {
            // Stroke
            glcd->plot(a + x, b + y, graphicState->getColor());
            glcd->plot(b + x, a + y, graphicState->getColor());
            glcd->plot(x - a, b + y, graphicState->getColor());
            glcd->plot(x - b, a + y, graphicState->getColor());
            glcd->plot(b + x, y - a, graphicState->getColor());
            glcd->plot(a + x, y - b, graphicState->getColor());
            glcd->plot(x - a, y - b, graphicState->getColor());
            glcd->plot(x - b, y - a, graphicState->getColor());
        }
        if (P < 0) {
            P += 3 + 2 * a++;
        } else {
            P += 5 + 2 * (a++ - b--);
        }
    } while (a <= b);
}
