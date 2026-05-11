#include "Files/SaveCommand.h"
#include "FileManager.h"

SaveCommand::SaveCommand(const std::string& filename): filename(filename) {}

void SaveCommand::execute(Canvas& canvas) {
    FileManager::SaveToFile(canvas, filename);
}