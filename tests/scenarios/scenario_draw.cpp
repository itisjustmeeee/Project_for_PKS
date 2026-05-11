#include <cassert>
#include <iostream>
#include "Canvas.h"
#include "Commands/DrawRectangleCommand.h"
#include "Commands/DrawPointCommand.h"
#include "Commands/DrawLineCommand.h"

int main() {
    Canvas canvas(20, 20);

    DrawPointCommand point(2, 2, '*');
    point.execute(canvas);

    DrawRectangleCommand rect(3, 3, 10, 10, '$');
    rect.execute(canvas);

    DrawLineCommand line(4, 4, 18, 11, '!');
    line.execute(canvas);

    assert(canvas.getGrid()[2][2] == '*');
    assert(canvas.getGrid()[3][3] == '$');
    assert(canvas.getGrid()[4][4] == '!');

    std::cout << "scenario_draw passed successfully\n";

    return 0;
}