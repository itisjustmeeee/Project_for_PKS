#include "Files/LoadCommand.h"
#include "FileManager.h"

LoadCommand::LoadCommand(const std::string& filename) : filename(filename) {}

void LoadCommand::execute(Canvas& canvas) {
    FileManager::LoadFromFile(canvas, filename);
}
