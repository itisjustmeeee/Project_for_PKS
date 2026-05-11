#pragma once
#include "Command.h"

class DrawPointCommand : public Command {
private:
    int x, y;
    char c;

public:
    DrawPointCommand(int x, int y, char c);

    void execute(Canvas& canvas) override;
};