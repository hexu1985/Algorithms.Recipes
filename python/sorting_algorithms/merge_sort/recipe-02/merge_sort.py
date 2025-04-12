#!/usr/bin/env python3
"""Sorting algorithms"""

def merge_sort(alist):
    copybuffer = alist[:]
    merge_sort_helper(alist, copybuffer, 0, len(alist) - 1)

def merge_sort_helper(alist, copybuffer, low, high):
    # alist: list being sorted
    # copybuffer: temp space needed during merge
    # low, high: bounds of sublist, [low, high]
    # middle: midpoint of sublist
    if low < high:
        middle = (low + high) // 2
        merge_sort_helper(alist, copybuffer, low, middle)
        merge_sort_helper(alist, copybuffer, middle+1, high)
        merge(alist, copybuffer, low, middle, high)

def merge(alist, copybuffer, low, middle, high):
    # alist: list that is being sorted
    # copybuffer: temp space needed during the merge process
    # low: beginning of first sorted sublist
    # middle: end of first sorted sublist
    # middle + 1: beginning of second sorted sublist
    # high: end of second sorted sublist
    i = low
    j = middle+1
    k = low
    while i <= middle and j <= high:
        if alist[i] < alist[j]:
            copybuffer[k] = alist[i]
            i = i + 1
        else:
            copybuffer[k] = alist[j]
            j = j + 1
        k = k + 1

    while i <= middle:
        copybuffer[k] = alist[i]
        i = i + 1
        k = k + 1

    while j <= high:
        copybuffer[k] = alist[j]
        j = j + 1
        k = k + 1
    
    for i in range(low, high + 1):
        alist[i] = copybuffer[i]


def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    merge_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
