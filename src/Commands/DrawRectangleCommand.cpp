#include "Commands/DrawRectangleCommand.h"

DrawRectangleCommand::DrawRectangleCommand(int x1, int y1, int x2, int y2, char c): x1(x1), y1(y1), x2(x2), y2(y2), c(c) {}

void DrawRectangleCommand::execute(Canvas& canvas) {
    canvas.drawRectangle(x1, y1, x2, y2, c);
}