#include <gtest/gtest.h>
#include <array>
#include "quick_sort.hpp"

TEST(func, median3)
{
    std::array<int, 3> alist;

    alist = std::to_array({1, 2, 3});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);

    alist = std::to_array({1, 3, 2});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);

    alist = std::to_array({2, 1, 3});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);

    alist = std::to_array({2, 3, 1});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);

    alist = std::to_array({3, 1, 2});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);

    alist = std::to_array({3, 2, 1});
    median3(std::span<int>(alist), 0, 2);
    EXPECT_EQ(2, alist[0]);
}


