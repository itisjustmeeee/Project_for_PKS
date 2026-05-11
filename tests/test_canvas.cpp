#include <gtest/gtest.h>
#include "Canvas.h"

TEST(CanvasTest, CreateCanvas) {
    Canvas canvas(10, 5);

    EXPECT_EQ(canvas.getWidth(), 10);
    EXPECT_EQ(canvas.getHeight(), 5);
}