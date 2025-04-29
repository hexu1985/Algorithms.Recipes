#pragma once

#include <span>
#include <utility>

template <typename T>
int partition(std::span<T> alist, int first, int last) {
    using std::swap;
    auto pivotvalue = alist[first];

    auto leftmark = first + 1;
    auto rightmark = last;

    bool done = false;
    while (!done) {
        while (leftmark <= rightmark && alist[leftmark] <= pivotvalue) {
            leftmark += 1;
        }

        while (alist[rightmark] >= pivotvalue && rightmark >= leftmark) {
            rightmark -= 1;
        }

        if (rightmark < leftmark) {
            done = true;
        } else {
            swap(alist[leftmark], alist[rightmark]);
        }
    }

    swap(alist[first], alist[rightmark]);

    return rightmark;
}

template <typename T>
void quick_sort_helper(std::span<T> alist, int first, int last) {
    if (first < last) {
        auto splitpoint = partition(alist, first, last);

        quick_sort_helper(alist, first, splitpoint-1);
        quick_sort_helper(alist, splitpoint+1, last);
    }
}

template <typename T>
void quick_sort(std::span<T> alist) {
    quick_sort_helper(alist, 0, int(alist.size())-1);
}
