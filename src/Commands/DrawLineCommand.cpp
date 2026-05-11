#include "Commands/DrawLineCommand.h"

DrawLineCommand::DrawLineCommand(int x1, int y1, int x2, int y2, char c) 
    : x1(x1), y1(y1), x2(x2), y2(y2), c(c) {}

void DrawLineCommand::execute(Canvas& canvas) {
    canvas.drawLine(x1, y1, x2, y2, c);
}