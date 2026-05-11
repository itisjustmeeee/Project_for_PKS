#pragma once
#include "Command.h"

class DrawRectangleCommand : public Command {
private:
    int x1, y1, x2, y2;
    char c;

public:
    DrawRectangleCommand(int x1, int y1, int x2, int y2, char c);

    void execute(Canvas& canvas) override;
};