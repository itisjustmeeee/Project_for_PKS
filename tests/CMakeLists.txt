enable_testing()

include(GoogleTest)

add_executable(runTests
    unit/test_canvas.cpp
    unit/test_commands.cpp
    unit/test_filemanager.cpp

    ../src/Canvas.cpp
    ../src/FileManager.cpp

    ../src/Commands/ClearCommand.cpp
    ../src/Commands/CreateCommand.cpp
    ../src/Commands/DrawLineCommand.cpp
    ../src/Commands/DrawPointCommand.cpp
    ../src/Commands/DrawRectangleCommand.cpp
    ../src/Commands/FillCommand.cpp
)

target_include_directories(runTests PRIVATE
    ../include
    ../src
)

target_link_libraries(runTests PRIVATE
    GTest::gtest
    GTest::gtest_main
)

gtest_discover_tests(runTests)

add_executable(scenario_draw
    scenarios/scenario_draw.cpp

    ../src/Canvas.cpp
    ../src/FileManager.cpp

    ../src/Commands/DrawLineCommand.cpp
    ../src/Commands/DrawPointCommand.cpp
    ../src/Commands/DrawRectangleCommand.cpp
)

target_include_directories(scenario_draw PRIVATE
    ../include
    ../src
)

add_executable(scenario_save_load
    scenarios/scenario_save_load.cpp

    ../src/Canvas.cpp
    ../src/FileManager.cpp
)

target_include_directories(scenario_save_load PRIVATE
    ../include
    ../src
)

add_executable(scenario_resize
    scenarios/scenario_resize.cpp

    ../src/Canvas.cpp
    ../src/FileManager.cpp

    ../src/Commands/DrawLineCommand.cpp
)

target_include_directories(scenario_resize PRIVATE
    ../include
    ../src
)