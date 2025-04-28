#pragma once

#include <span>
#include <utility>

template <typename T>
void bubble_sort(std::span<T> alist) {
    using std::swap;
    for (int passnum = alist.size()-1; passnum > 0; passnum--) {
        for (int i = 0; i < passnum; i++) {
            if (alist[i] > alist[i+1]) {
                swap(alist[i], alist[i+1]);
            } 
        }
    }
}
