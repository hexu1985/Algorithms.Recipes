#!/usr/bin/env python3
"""Sorting algorithms"""

def merge_sort(alist):
    #print("Splitting ", alist)
    if len(alist) > 1:
        mid = len(alist) // 2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        merge_sort(lefthalf)
        merge_sort(righthalf)

        i = 0
        j = 0
        k = 0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i = i + 1
            else:
                alist[k] = righthalf[j]
                j = j + 1
            k = k + 1

        while i < len(lefthalf):
            alist[k] = lefthalf[i]
            i = i + 1
            k = k + 1

        while j < len(righthalf):
            alist[k] = righthalf[j]
            j = j + 1
            k = k + 1
    #print("Merging ", alist)


def main():
    a_list = [54, 26, 93, 17, 77, 31, 44, 55, 20]
    print(f"before sorting: {a_list}")
    merge_sort(a_list)
    print(f"after sorting: {a_list}")
    assert a_list == sorted(a_list)

if __name__ == "__main__":
    main()
