#!/usr/bin/env python3
"""Sorting algorithms"""

def quick_sort(alist):
    quick_sort_helper(alist, 0, len(alist)-1)

def quick_sort_helper(alist, first, last):
    if first < last:
        splitpoint = partition(alist, first, last)

        quick_sort_helper(alist, first, splitpoint-1)
        quick_sort_helper(alist, splitpoint+1, last)

def partition(alist, first, last):
    median3(alist, first, last)
    pivotvalue = alist[first]

    leftmark = first + 1
    rightmark = last

    done = False
    while not done:

        while leftmark <= rightmark and alist[leftmark] <= pivotvalue:
            leftmark = leftmark + 1

        while alist[rightmark] >= pivotvalue and rightmark >= leftmark:
            rightmark = rightmark - 1

        if rightmark < leftmark:
            done = True
        else:
            temp = alist[leftmark]
            alist[leftmark] = alist[rightmark]
            alist[rightmark] = temp

    temp = alist[first]
    alist[first] = alist[rightmark]
    alist[rightmark] = temp

    return rightmark

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

    if medianIndex != first:
        temp = alist[first]
        alist[first] = alist[medianIndex]
        alist[medianIndex] = temp

def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    quick_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
