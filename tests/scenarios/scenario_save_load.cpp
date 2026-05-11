#include <gtest/gtest.h>
#include "Canvas.h"
#include "FileManager.h"

TEST(FileManagerTest, SaveAndLoadRectangle) {
    Canvas canvas(10, 10);

    canvas.drawRectangle(1, 1, 5, 5, '#');

    FileManager::SaveToFile(canvas, "test.txt");

    Canvas loaded(1, 1);

    FileManager::LoadFromFile(loaded, "test.txt");

    EXPECT_EQ(loaded.getGrid()[1][1], '#');
}