#!/usr/bin/env python3

def median3(alist, first, last):
    center = (first + last) // 2
    medianIndex = first

    if alist[first] < alist[last]:
        if alist[center] < alist[first]:
            medianIndex = first
        elif alist[last] < alist[center]:
            medianIndex = last
        else:
            medianIndex = center
    else:
        if alist[center] < alist[last]:
            medianIndex = last
        elif alist[first] < alist[center]:
            medianIndex = first
        else:
            medianIndex = center
    return medianIndex

def test_median3():
    alist = [1, 2, 3]
    assert alist[median3(alist, 0, 2)] == 2

    alist = [1, 3, 2]
    assert alist[median3(alist, 0, 2)] == 2

    alist = [2, 1, 3]
    assert alist[median3(alist, 0, 2)] == 2

    alist = [2, 3, 1]
    assert alist[median3(alist, 0, 2)] == 2

    alist = [3, 1, 2]
    assert alist[median3(alist, 0, 2)] == 2

    alist = [3, 2, 1]
    assert alist[median3(alist, 0, 2)] == 2
