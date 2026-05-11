#include "Commands/DrawPointCommand.h"

DrawPointCommand::DrawPointCommand(int x, int y, char c) : x(x), y(y), c(c) {}

void DrawPointCommand::execute(Canvas& canvas) {
    canvas.drawPoint(x, y, c);
}