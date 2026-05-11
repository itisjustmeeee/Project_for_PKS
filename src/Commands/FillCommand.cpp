#include "Commands/FillCommand.h"

FillCommand::FillCommand(int x, int y, char fillChar): x(x), y(y), fillChar(fillChar) {}

void FillCommand::execute(Canvas& canvas) {
    canvas.fill(x, y, fillChar);
}