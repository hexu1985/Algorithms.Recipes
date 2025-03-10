#!/usr/bin/env python3
"""
Testing the Sorting algorithms
Roman Yasinovskyy, 2017
Karina E. Hoff, 2018
"""


# Specifies the absolute path to the pythonds3 module
import os
import sys

sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), ".")))

import pytest
from random import randint
from bubble_sort import bubble_sort
from selection_sort import selection_sort
from insertion_sort import insertion_sort
from shell_sort import shell_sort


class TestSortingMethods:
    """Testing the sorting algorithms"""

    @pytest.fixture(autouse=True)
    def setup_class(self):
        """Setting up"""
        self.lst_to_sort = [randint(100, 999) for _ in range(100)]
        self.test_lst = self.lst_to_sort[:]
        self.test_lst.sort()

    def test_bubble_sort(self):
        """Testing bubble_sort"""
        print(f"self.lst_to_sort is sort? {self.lst_to_sort == self.test_lst}")
        bubble_sort(self.lst_to_sort)
        assert self.lst_to_sort == self.test_lst

    def test_selection_sort(self):
        """Testing selection_sort"""
        print(f"self.lst_to_sort is sort? {self.lst_to_sort == self.test_lst}")
        selection_sort(self.lst_to_sort)
        assert self.lst_to_sort == self.test_lst

    def test_insertion_sort(self):
        """Testing insertion_sort"""
        print(f"self.lst_to_sort is sort? {self.lst_to_sort == self.test_lst}")
        insertion_sort(self.lst_to_sort)
        assert self.lst_to_sort == self.test_lst

    def test_shell_sort(self):
        """Testing shell_sort"""
        print(f"self.lst_to_sort is sort? {self.lst_to_sort == self.test_lst}")
        shell_sort(self.lst_to_sort)
        assert self.lst_to_sort == self.test_lst


if __name__ == "__main__":
    pytest.main(["test_sorting_algorithms.py"])


