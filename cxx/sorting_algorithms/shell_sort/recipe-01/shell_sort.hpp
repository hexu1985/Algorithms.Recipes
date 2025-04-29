#pragma once

#include <span>

template <typename T>
void gap_insertion_sort(std::span<T> alist, int start, int gap) {
    for (int i = start+gap; i < alist.size(); i += gap) {
        auto currentvalue = alist[i];
        auto position = i;
        while (position >= gap && alist[position-gap] > currentvalue) {
            alist[position] = alist[position-gap];
            position -= gap;
        }

        alist[position] = currentvalue;
    }
}

template <typename T>
void shell_sort(std::span<T> alist) {
    auto sublistcount = alist.size() / 2;
    while (sublistcount > 0) {
        for (int startposition = 0; startposition < sublistcount; startposition++) {
            gap_insertion_sort(alist, startposition, sublistcount);
        }

        sublistcount /= 2;
    }
}
