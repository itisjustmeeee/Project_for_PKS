cmake_minimum_required(VERSION 3.10)

project(ConsolePaint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/Canvas.cpp
    src/ClearCommand.cpp
    src/CommandHandler.cpp
    src/CreateCommand.cpp
    src/DrawLineCommand.cpp
    src/DrawPointCommand.cpp
    src/DrawRectangleCommand.cpp
    src/FileManager.cpp
    src/FillCommand.cpp
    src/LoadCommand.cpp
    src/SaveCommand.cpp
)

add_executable(ConsolePaint ${SOURCES})

target_include_directories(ConsolePaint PUBLIC include)

if (MSVC)
    target_compile_options(ConsolePaint PRIVATE /W4)
else()
    target_compile_options(ConsolePaint PRIVATE -Wall -Wextra)
endif()