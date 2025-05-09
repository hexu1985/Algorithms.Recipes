#pragma once

#include <span>
#include <utility>

template <typename T>
void median3(std::span<T> alist, int first, int last) {
    using std::swap;
    auto center = (first + last)/2;
    auto medianIndex = first;

    if (alist[first] < alist[last]) {
        if (alist[center] < alist[first]) {
            medianIndex = first;
        } else if (alist[last] < alist[center]) {
            medianIndex = last;
        } else {
            medianIndex = center;
        }
    } else {
        if (alist[center] < alist[last]) {
            medianIndex = last;
        } else if (alist[first] < alist[center]) {
            medianIndex = first;
        } else {
            medianIndex = center;
        }
    }

    if (medianIndex != first) {
        swap(alist[first], alist[medianIndex]);
    }
}

template <typename T>
int partition(std::span<T> alist, int first, int last) {
    using std::swap;
    median3(alist, first, last);
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
