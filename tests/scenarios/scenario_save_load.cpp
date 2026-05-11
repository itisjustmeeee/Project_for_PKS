#include <cassert>
#include <iostream>
#include "Canvas.h"
#include "FileManager.h"

int main() {
    Canvas canvas(5, 5);

    canvas.drawLine(1, 1, 3, 4, '*');

    FileManager::SaveToFile(canvas, "test1.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "test1.txt");

    assert(loaded.getGrid()[1][1] == '*');

    std::cout << "scenario_save_load passed successfully\n";

    return 0;
}