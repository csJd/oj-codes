#
# @lc app=leetcode id=15 lang=python3
#
# [15] 3Sum
#

'''
Tags
array | two-pointers

Companies
adobe | amazon | bloomberg | facebook | microsoft

Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
'''

from bisect import bisect_left
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        new_nums = nums[:3]
        for i in range(3, len(nums)):
            if nums[i] != nums[i-3]:
                new_nums.append(nums[i])
        nums = new_nums

        length = len(nums)
        res = set()
        for i in range(length):
            for j in range(i+1, length):
                r = -nums[i] - nums[j]
                r_ind = bisect_left(nums, r, lo=j+1)
                if r_ind < length and nums[r_ind] == r:
                    res.add((nums[i], nums[j], nums[r_ind]))
        res = [list(tup) for tup in res]
        return res
