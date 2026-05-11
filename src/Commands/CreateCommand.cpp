#include "Commands/CreateCommand.h"
#include <iostream>

CreateCommand::CreateCommand(int w, int h) : width(w), height(h) {}

void CreateCommand::execute(Canvas& canvas) {
    if (width <= 0 || height <= 0 || width > 100 || height > 40) {
        std::cout << "Invalid canvas size!\n";
        return;
    }

    canvas.resize(width, height);
}