#include <gtest/gtest.h>
#include "window/window.hpp"

TEST(BasicTests, GTestSetup)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}