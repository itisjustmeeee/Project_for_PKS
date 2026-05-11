#pragma once
#include "Command.h"

class FillCommand : public Command {
private:
    int x, y;
    char fillChar;

public:
    FillCommand(int x, int y, char fillChar);

    void execute(Canvas& canvas) override;
};