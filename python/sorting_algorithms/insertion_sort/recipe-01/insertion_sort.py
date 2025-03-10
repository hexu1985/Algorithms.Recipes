#!/usr/bin/env python3
"""Sorting algorithms"""

def insertion_sort(alist):
    for index in range(1, len(alist)):

        currentvalue = alist[index]
        position = index

        while position > 0 and alist[position-1] > currentvalue:
            alist[position] = alist[position-1]
            position = position-1

        alist[position] = currentvalue


def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    insertion_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
