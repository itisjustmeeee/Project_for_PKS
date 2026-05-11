#include <string>
#include <iostream>
#include <sstream>

#include "CommandHandler.h"
#include "Command.h"
#include "Commands/CreateCommand.h"
#include "Commands/DrawPointCommand.h"
#include "Commands/DrawLineCommand.h"
#include "Commands/ClearCommand.h"
#include "Commands/DrawRectangleCommand.h"
#include "Commands/FillCommand.h"
#include "Files/SaveCommand.h"
#include "Files/LoadCommand.h"

void CommandHandler::printHelp() const {
    std::cout << "ASCII Paint commands:\n";
    std::cout << "create w h --- create canvas\n";
    std::cout << "point x y c --- draw point with selected char\n";
    std::cout << "line x1 y1 x2 y2 c --- draw line with selected char\n";
    std::cout << "rect x1 y1 x2 y2 c --- draw rectangle with selected char\n";
    std::cout << "fill x y c --- fill canvas with selected char starting at sertain point\n";
    std::cout << "clear --- clear canvas\n";
    std::cout << "save filename --- save canvas to file\n";
    std::cout << "load filename --- load canvas from file\n";
    std::cout << "exit --- exit Paint\n";
}

void CommandHandler::run() {
    printHelp();

    std::string input;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        std::unique_ptr<Command> cmd(parseCommand(input));
        if (cmd) {
            cmd->execute(canvas);
            canvas.display();
        }
    }
}

CommandHandler::CommandHandler(int width, int height) : canvas(width, height) {}

Command* CommandHandler::parseCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string cmd;
    
    if (!(iss >> cmd)) {
        return nullptr;
    }

    if (cmd == "create") {
        int w, h;
        if (!(iss >> w >> h)) {
            std::cout << "Invalid arguments for create\n";
            return nullptr;
        }
        return new CreateCommand(w, h);
    }

    else if (cmd == "point") {
        int x, y;
        char c;
        if (!(iss >> x >> y >> c)) {
            std::cout << "Invalid arguments for point\n";
            return nullptr;
        }
        return new DrawPointCommand(x, y, c);
    }

    else if (cmd == "line") {
        int x1, y1, x2, y2;
        char c;
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> c)) {
            std::cout << "Invalid arguments for line\n";
            return nullptr;
        }
        return new DrawLineCommand(x1, y1, x2, y2, c);
    }
    
    else if (cmd == "clear") {
        return new ClearCommand();
    }

    else if (cmd == "rect") {
        int x1, y1, x2, y2;
        char c;
        if (!(iss >> x1 >> y1 >> x2 >> y2 >> c)) {
            std::cout << "Invalid arguments for line\n";
            return nullptr;
        }
        return new DrawRectangleCommand(x1, y1, x2, y2, c);
    }

    else if (cmd == "fill") {
        int x, y;
        char c;
        if (!(iss >> x >> y >> c)) {
            std::cout << "Invalid arguments for line\n";
            return nullptr;
        }
        return new FillCommand(x, y, c);
    }

    else if (cmd == "save") {
        std::string filename;

        std::getline(iss >> std::ws, filename);

        if (filename.empty()) {
            std::cout << "Invalid arguments for save\n";
            return nullptr;
        }

        return new SaveCommand(filename);
    }

    else if (cmd == "load") {
        std::string filename;

        std::getline(iss >> std::ws, filename);

        if (filename.empty()) {
            std::cout << "Invalid arguments for load\n";
            return nullptr;
        }

        return new LoadCommand(filename);
    }

    std::cout << "Unknown command\n";
    return nullptr;
}