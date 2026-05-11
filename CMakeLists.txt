cmake_minimum_required(VERSION 3.10)

project(ConsolePaint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

set(SOURCES
    src/main.cpp
    src/Canvas.cpp
    src/CommandHandler.cpp
    src/FileManager.cpp

    src/Commands/ClearCommand.cpp
    src/Commands/CreateCommand.cpp
    src/Commands/DrawLineCommand.cpp
    src/Commands/DrawPointCommand.cpp
    src/Commands/DrawRectangleCommand.cpp
    src/Commands/FillCommand.cpp

    src/Files/LoadCommand.cpp
    src/Files/SaveCommand.cpp
)

add_executable(ConsolePaint ${SOURCES})

target_include_directories(ConsolePaint PUBLIC 
    include
    src
)

add_subdirectory(tests)

if (MSVC)
    target_compile_options(ConsolePaint PRIVATE /W4)
else()
    target_compile_options(ConsolePaint PRIVATE -Wall -Wextra)
endif()