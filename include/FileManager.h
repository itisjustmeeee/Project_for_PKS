#pragma once
#include <string>
#include "Canvas.h"

class FileManager {
public:
    static void SaveToFile(const Canvas& canvas, const std::string& filename);
    static void LoadFromFile(Canvas& canvas, const std::string& filename);
};