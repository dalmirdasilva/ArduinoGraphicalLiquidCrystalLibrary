/**
 * Arduino Graphic LCD Library
 * 
 * GlcdDrawer.cpp
 * 
 * The header functions to draw in a glcd plane.
 * 
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_LIBRARY_GLCD_DRAWER_CPP__
#define __ARDUINO_LIBRARY_GLCD_DRAWER_CPP__ 1

#include "GlcdDrawer.h"

GlcdDrawer::GlcdDrawer(Glcd *glcd, GlcdGraphicState *graphicState) : glcd(glcd), graphicState(graphicState) {
}

void GlcdDrawer::setGlcd(Glcd *glcd) {
    this->glcd = glcd;
}

void GlcdDrawer::setGraphicState(GlcdGraphicState *graphicState) {
    this->graphicState = graphicState;
}

Glcd *GlcdDrawer::getGlcd() {
    return glcd;
}

GlcdGraphicState *GlcdDrawer::getGraphicState() {
    return graphicState;
}

void GlcdDrawer::line(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {

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

void GlcdDrawer::rect(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2) {

    if (graphicState->getFill()) {

        // Find the y min and max
        unsigned char y_min, y_max;

        if (y1 < y2) {
            y_min = y1;
            y_max = y2;
        } else {
            y_min = y2;
            y_max = y1;
        }

        // Drawer lines to fill the rectangle
        for (; y_min <= y_max; y_min++) {
            line(x1, y_min, x2, y_min);
        }
    } else {

        // Drawer the 4 sides
        line(x1, y1, x2, y1);
        line(x1, y2, x2, y2);
        line(x1, y1, x1, y2);
        line(x2, y1, x2, y2);
    }
}

void GlcdDrawer::circle(unsigned char x, unsigned char y, unsigned char radius) {

    int P = 1 - radius;
    unsigned char a = 0;
    unsigned char b = radius;
    unsigned char i = 0;

    // To fit the glcd screen
    if (x < radius) {
        x = radius;
    } else if ((GLCD_WIDTH - 1 - x) < radius) {
        x = GLCD_WIDTH - 1 - radius;
    }

    if (y < radius) {
        y = radius;
    } else if ((GLCD_HEIGHT - 1 - y) < radius) {
        y = GLCD_HEIGHT - 1 - radius;
    }

    do {

        // Fill
        if (graphicState->getFill()) {

            line(x - a, y + b, x + a, y + b);
            line(x - a, y - b, x + a, y - b);
            line(x - b, y + a, x + b, y + a);
            line(x - b, y - a, x + b, y - a);

        // Stroke
        } else {

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

#endif /* __ARDUINO_LIBRARY_GLCD_DRAWER_CPP__ */
