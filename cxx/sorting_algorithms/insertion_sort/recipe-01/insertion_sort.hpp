#pragma once

#include <span>
#include <utility>

template <typename T>
void insertion_sort(std::span<T> alist) {
    for (int index = 1; index < alist.size(); index++) {
        auto currentvalue = alist[index];
        auto position = index;
        while (position > 0 && alist[position-1] > currentvalue) {
            alist[position] = alist[position-1];
            position -= 1;
        }
        alist[position] = currentvalue;
    }
}
