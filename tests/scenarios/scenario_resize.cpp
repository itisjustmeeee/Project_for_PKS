#include <cassert>
#include <iostream>
#include "Commands/DrawLineCommand.h"
#include "Canvas.h"

int main() {
    Canvas canvas(5, 5);
    DrawLineCommand line(1, 1, 3, 4, '*');
    line.execute(canvas);

    assert(canvas.getGrid()[1][1] == '*');

    canvas.resize(10, 8);

    assert(canvas.getHeight() == 8);
    assert(canvas.getWidth() == 10);

    assert(canvas.getGrid()[1][1] == '.');

    for (int y = 0; y < canvas.getHeight(); y++) {
        for (int x = 0; x < canvas.getWidth(); x++) {
            assert(canvas.getGrid()[y][x] == '.');
        }
    }

    std::cout << "scenario_resize passed successfully\n";

    return 0;
}