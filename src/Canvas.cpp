#include "Canvas.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

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

int Canvas::getWidth() const {
    return width;
}

int Canvas::getHeight() const {
    return height;
}

const std::vector<std::string>& Canvas::getGrid() const {
    return grid;
}

void Canvas::setGrid(const std::vector<std::string>& newGrid) {
    if (newGrid.empty()) return;

    size_t newHeight = newGrid.size();
    size_t newWidth = newGrid[0].size();

    for (const auto& row : newGrid) {
        if (row.size() != newWidth) {
            std::cerr << "Invalid grid format\n";
            return;
        }
    }

    width = newWidth;
    height = newHeight;
    grid = newGrid;
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

void Canvas::drawRectangle(int x1, int y1, int x2, int y2, char c) {
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);

    drawLine(x1, y1, x2, y1, c);
    drawLine(x1, y2, x2, y2, c);
    drawLine(x1, y1, x1, y2, c);
    drawLine(x2, y1, x2, y2, c);
}

void Canvas::fill(int x, int y, char newChar) {
    if (!isValid(x, y)) return;

    char target = grid[y][x];
    if (target == newChar) return;

    std::stack<std::pair<int, int>> st;
    st.push({x, y});

    while(!st.empty()) {
        auto [cx, cy] = st.top();
        st.pop();

        if (!isValid(cx, cy)) continue;
        if (grid[cy][cx] != target) continue;
        
        grid[cy][cx] = newChar;

        st.push({cx + 1, cy});
        st.push({cx - 1, cy});
        st.push({cx, cy + 1});
        st.push({cx, cy - 1});
    }
 }