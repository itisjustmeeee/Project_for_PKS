set(TEST_SOURCES
    test_canvas.cpp
    test_commands.cpp
    test_filemanager.cpp
    scenarios/scenario_save_load.cpp
)

add_executable(runTests
    ${TEST_SOURCES}

    ../src/Canvas.cpp
    ../src/FileManager.cpp

    ../src/Commands/CreateCommand.cpp
    ../src/Commands/DrawPointCommand.cpp
    ../src/Commands/DrawLineCommand.cpp
    ../src/Commands/DrawRectangleCommand.cpp
    ../src/Commands/FillCommand.cpp
    ../src/Commands/ClearCommand.cpp

    ../src/Files/LoadCommand.cpp
    ../src/Files/SaveCommand.cpp
)

target_include_directories(runTests PRIVATE
    ../include
)

target_link_libraries(runTests
    gtest
    gtest_main
)

include(GoogleTest)

gtest_discover_tests(runTests)