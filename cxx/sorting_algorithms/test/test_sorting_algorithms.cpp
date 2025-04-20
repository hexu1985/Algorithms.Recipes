#include <gtest/gtest.h>
#include <iostream>
#include <algorithm>
#include <span>
#include <string_view>
#include "random.hpp"
#include "bubble_sort.hpp"

template <typename T>
void print_list(std::string_view title, std::span<T> items) {
    std::cout << title << ": [";
    for (const auto& item : items) { // spans are iterable
        std::cout << item << ", ";
    }
    std::cout << "]\n";
}

class TestSortingMethods: public testing::Test {
protected:
    virtual void SetUp()
    {
        for (int i=0; i < 100; i++) {
            test_lst.push_back(randint(100, 999));
        }
        sorted_lst = test_lst;
        std::sort(sorted_lst.begin(), sorted_lst.end());

        std::span<int> front_10_items{test_lst.begin(), 10};
        print_list("front 10 items before sorting", front_10_items);
    }

    virtual void TearDown()
    {
        std::span<int> front_10_items{test_lst.begin(), 10};
        print_list("front 10 items after sorting", front_10_items);
    }

    std::vector<int> sorted_lst;
    std::vector<int> test_lst;
};

TEST_F(TestSortingMethods, test_bubble_sort) {
    bubble_sort(std::span<int>(test_lst));
    EXPECT_EQ(test_lst, sorted_lst);
}

