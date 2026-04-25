#pragma once
#include <vector>
#include <string>

class Canvas {
private:
    int width;
    int height;
    std::vector<std::string> grid;

    bool isValid(int x, int y) const;
    void setPixel(int x, int y, char c);

public:
    Canvas(int w, int h);
    void resize(int w, int h);

    void clear();
    void display() const;

    void drawPoint(int x, int y, char c);
    void drawLine(int x1, int y1, int x2, int y2, char c);
    void drawRectangle(int x1, int y1, int x2, int y2, char c);
    void fill(int x, int y, char c);

    char getPixel(int x, int y) const;
};

