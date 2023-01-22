#include <window/window.hpp>
#include <gtest/gtest.h>

TEST(WindowTests, TestWindowCreation)
{
    Window window(1280, 720, "My Minecraft Clone");
    EXPECT_TRUE(window.shouldClose());
}

TEST(WindowTests, TestWindowCreationFullscreen)
{
    Window window(1280, 720, "My Minecraft Clone", true);
    EXPECT_TRUE(window.shouldClose());
}

TEST(WindowTests, TestWindowUpdate)
{
    Window window(1280, 720, "My Minecraft Clone");
    window.update();
    EXPECT_TRUE(window.shouldClose());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}