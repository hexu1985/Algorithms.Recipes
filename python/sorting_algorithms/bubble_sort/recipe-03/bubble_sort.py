#!/usr/bin/env python3
"""Sorting algorithms"""

def bubble_sort(alist):
    for passnum in range(len(alist)-1, 0, -1):
        exchanges = False
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                temp = alist[i]
                alist[i] = alist[i+1]
                alist[i+1] = temp
                exchanges = True
        if not exchanges:
            break


def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    bubble_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
