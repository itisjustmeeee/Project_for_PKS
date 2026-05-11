#pragma once
#include "Command.h"
#include <string>

class SaveCommand : public Command {
private:
    std::string filename;

public:
    SaveCommand(const std::string& filename);

    void execute(Canvas& canvas) override;
};