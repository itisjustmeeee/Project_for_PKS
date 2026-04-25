#pragma once
#include <string>
#include "Canvas.h"
#include "Command.h"

class CommandHandler {
private:
    Canvas canvas;

public:
    CommandHandler(int width, int height);

    void printHelp() const;

    void run();
    Command* parseCommand(const std::string& input);
};