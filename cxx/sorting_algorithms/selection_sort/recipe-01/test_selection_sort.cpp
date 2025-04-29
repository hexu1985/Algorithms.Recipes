#include "selection_sort.hpp"
#include <iostream>
#include <string_view>
#include <vector>

template <typename T>
void print_list(std::string_view title, std::span<T> items) {
    std::cout << title << ": [";
    for (const auto& item : items) { // spans are iterable
        std::cout << item << ", ";
    }
    std::cout << "]\n";
}

int main() {
    int data[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
    std::span<int> a_list(data);
    print_list("before sorting", a_list);
    selection_sort(a_list);
    print_list("after sorting", a_list);
    
    return 0;
}

