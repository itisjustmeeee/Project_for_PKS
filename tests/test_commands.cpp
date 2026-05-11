#include <gtest/gtest.h>
#include "Canvas.h"
#include "Commands/DrawPointCommand.h"
#include "Commands/DrawLineCommand.h"
#include "Commands/DrawRectangleCommand.h"
#include "Commands/FillCommand.h"
#include "Commands/ClearCommand.h"
#include "Commands/CreateCommand.h"

TEST(CommandTest, DrawPointCommand) {
    Canvas canvas(5, 5);

    DrawPointCommand cmd(2, 2, '*');

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getGrid()[2][2], '*');
}

TEST(CommandTest, DrawLineCommand) {
    Canvas canvas(10, 10);

    DrawLineCommand cmd(0, 0, 5, 5, '#');

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getGrid()[3][3], '#');
}

TEST(CommandTest, DrawRectangleCommand) {
    Canvas canvas(10, 10);

    DrawRectangleCommand cmd(1, 1, 5, 5, '@');

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getGrid()[1][1], '@');
    EXPECT_EQ(canvas.getGrid()[1][5], '@');
    EXPECT_EQ(canvas.getGrid()[5][1], '@');
    EXPECT_EQ(canvas.getGrid()[5][5], '@');
}

TEST(CommandTest, FillCommand) {
    Canvas canvas(5, 5);

    FillCommand cmd(2, 2, '*');

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getGrid()[2][2], '*');
}

TEST(CommandTest, ClearCommand) {
    Canvas canvas(5, 5);

    canvas.drawPoint(2, 2, '*');

    ClearCommand cmd;

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getGrid()[2][2], '.');
}

TEST(CommandTest, CreateCommand) {
    Canvas canvas(5, 5);

    CreateCommand cmd(20, 10);

    cmd.execute(canvas);

    EXPECT_EQ(canvas.getWidth(), 20);
    EXPECT_EQ(canvas.getHeight(), 10);
}

TEST(CommandTest, ResizeCommand) {
    Canvas canvas(5, 5);

    canvas.drawPoint(2, 2, '*');
    EXPECT_EQ(canvas.getGrid()[2][2], '*');

    canvas.resize(10, 8);

    EXPECT_EQ(canvas.getWidth(), 10);
    EXPECT_EQ(canvas.getHeight(), 8);

    EXPECT_EQ(canvas.getGrid()[2][2], '.');

    for (int y = 0; y < canvas.getHeight(); y++) {
        for (int x = 0; x < canvas.getWidth(); x++) {
            EXPECT_EQ(canvas.getGrid()[y][x], '.');
        }
    }
}