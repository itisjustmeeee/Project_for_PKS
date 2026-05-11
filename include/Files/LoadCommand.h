#pragma once
#include "Command.h"
#include <string>

class LoadCommand : public Command {
private:
    std::string filename;

public:
    LoadCommand(const std::string& filename);

    void execute(Canvas& canvas) override;
};