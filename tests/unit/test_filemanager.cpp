#include <gtest/gtest.h>
#include "Canvas.h"
#include "FileManager.h"

TEST(FileManagerTest, SaveAndLoadCanvas) {
    Canvas canvas(5, 5);

    canvas.drawPoint(2, 2, '*');

    FileManager::SaveToFile(canvas, "test.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "test.txt");

    EXPECT_EQ(loaded.getGrid()[2][2], '*');
}

TEST(FileManagerTest, LoadCanvasSize) {
    Canvas canvas(10, 8);

    FileManager::SaveToFile(canvas, "size_test.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "size_test.txt");

    EXPECT_EQ(loaded.getWidth(), 10);
    EXPECT_EQ(loaded.getHeight(), 8);
}

TEST(FileManagerTest, SaveEmptyCanvas) {
    Canvas canvas(5, 5);

    FileManager::SaveToFile(canvas, "empty.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "empty.txt");

    EXPECT_EQ(loaded.getGrid()[0][0], '.');
}

TEST(FileManagerTest, SaveRectangle) {
    Canvas canvas(10, 10);

    canvas.drawRectangle(1, 1, 5, 5, '#');

    FileManager::SaveToFile(canvas, "rect.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "rect.txt");

    EXPECT_EQ(loaded.getGrid()[1][1], '#');
}

TEST(FileManagerTest, SaveLine) {
    Canvas canvas(10, 10);

    canvas.drawLine(0, 0, 5, 5, '*');

    FileManager::SaveToFile(canvas, "line.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "line.txt");

    EXPECT_EQ(loaded.getGrid()[3][3], '*');
}

