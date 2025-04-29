#pragma once

#include <span>
#include <utility>

template <typename T>
void selection_sort(std::span<T> alist) {
    using std::swap;
    for (int fillslot = alist.size()-1; fillslot > 0; fillslot--) {
        int positionOfMax = 0;
        for (int location = 1; location < fillslot+1; location++) {
            if (alist[location] > alist[positionOfMax]) {
                positionOfMax = location;
            }
        }
        swap(alist[fillslot], alist[positionOfMax]);
    }
}
