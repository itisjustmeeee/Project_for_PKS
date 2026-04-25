#pragma once
#include "Canvas.h"

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(Canvas& canvas) = 0;
};