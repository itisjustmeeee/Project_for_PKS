#include "Canvas.h"
#include <string>
#include <cstdlib>
#include <iostream>

Canvas::Canvas(int w, int h) : width(w), height(h) {
    grid.resize(height, std::string(width, '.'));
}

void Canvas::display() const {
    std::cout << std::string(width + 2, '-') << std::endl;

    for (const auto& row : grid) {
        std::cout << '|' << row << '|' << std::endl;
    }

    std::cout << std::string(width + 2, '-') << std::endl;
}

bool Canvas::isValid(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Canvas::setPixel(int x, int y, char c) {
    if (isValid(x, y)) {
        grid[y][x] = c;
    }
}

void Canvas::resize(int w, int h) {
    width = w;
    height = h;
    grid.clear();
    grid.resize(height, std::string(width, '.'));
}

void Canvas::drawPoint(int x, int y, char c) {
    if (isValid(x, y)) {
        setPixel(x, y, c);
    }
}

void Canvas::drawLine(int x1, int y1, int x2, int y2, char c) {
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    
    int signX = (x1 < x2) ? 1 : -1;
    int signY = (y1 < y2) ? 1 : -1;
    
    int d = deltaX - deltaY;

    int maxSteps = width * height;
    int steps = 0;

    while (true) {
        if (isValid(x1, y1)){
            setPixel(x1, y1, c);
        }

        if (++steps > maxSteps) break;

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int d2 = d * 2;

        if (d2 > -deltaY) {
            d -= deltaY;
            x1 += signX;
        }

        if(d2 < deltaX) {
            d += deltaX;
            y1 += signY;
        }
    }
}

void Canvas::clear() {
    grid.assign(height, std::string(width, '.'));
}