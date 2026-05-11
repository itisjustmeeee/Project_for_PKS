#pragma once
#include "Command.h"

class ClearCommand : public Command {
public:
    void execute(Canvas& canvas) override;
};