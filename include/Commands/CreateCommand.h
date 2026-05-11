#pragma once
#include "Command.h"

class CreateCommand : public Command {
private:
    int width, height;

public:
    CreateCommand(int w, int h);

    void execute(Canvas& canvas) override;
};