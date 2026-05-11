#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <vector>

void FileManager::SaveToFile(const Canvas& canvas, const std::string& filename) {
    std::ofstream out(filename);

    if (!out) {
        std::cerr << "Error opening file for writing\n";
        return;
    }

    out << canvas.getWidth() << ' ' << canvas.getHeight() << '\n';
    
    for (const auto& row : canvas.getGrid()) {
        out << row << '\n';
    }

    out.close();
}

void FileManager::LoadFromFile(Canvas& canvas, const std::string& filename) {
    std::ifstream in(filename);

    if (!in) {
        std::cerr << "Error opening file for reading\n";
        return;
    }

    int w, h;
    
    if (!(in >> w >> h)) {
        std::cerr << "Invalid file format\n";
        return;
    }

    in.ignore();

    std::vector<std::string> newGrid;

    for (int i = 0; i < h; i++) {
        std::string row;
        std::getline(in, row);

        if (row.size() != w) {
            std::cerr << "Invalid row size\n";
            return;
        }

        newGrid.push_back(row);
    }

    canvas.setGrid(newGrid);

    in.close();
}