#!/usr/bin/env python3
"""Sorting algorithms"""

def shell_sort(alist):
    sublistcount = len(alist) // 2
    while sublistcount > 0:
        for startposition in range(sublistcount):
            gap_insertion_sort(alist, startposition, sublistcount)
#        print("After increments of size", sublistcount, "The list is", alist)

        sublistcount = sublistcount // 2

def gap_insertion_sort(alist, start, gap): 
    for i in range(start+gap, len(alist), gap):
        currentvalue = alist[i]
        position = i

        while position >= gap and alist[position-gap] > currentvalue:
            alist[position] = alist[position-gap]
            position = position-gap

        alist[position] = currentvalue


def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    shell_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
