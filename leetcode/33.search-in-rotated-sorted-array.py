#
# @lc app=leetcode id=33 lang=python3
#
# [33] Search in Rotated Sorted Array
#
# https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (32.86%)
# Likes:    2342
# Dislikes: 305
# Total Accepted:    409K
# Total Submissions: 1.2M
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
#
# (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
#
# You are given a target value to search. If found in the array return its
# index, otherwise return -1.
#
# You may assume no duplicate exists in the array.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# Example 1:
#
#
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
#
#
# Example 2:
#
#
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1
#
#

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        length = len(nums)
        le, ri = 0, length - 1
        while(le <= ri):
            mid = (le + ri) >> 1
            if nums[mid] >= nums[0]:  # mid is in the left of pivot
                le = mid + 1
            else:  # mid if in the right of pivot
                ri = mid - 1
        pivot = ri + 1

        if length > 0 and target >= nums[0]:
            le, ri = 0, pivot - 1
        else:
            le, ri = pivot, length - 1

        while le <= ri:
            mid = (le + ri) >> 1
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                le = mid + 1
            else:
                ri = mid - 1
        return -1


def main():
    solu = Solution()
    print(solu.search([2, 1], 1))
    print(solu.search([4, 5, 6, 7, 0, 1, 2], 3))
    print(solu.search([], 0))
    print(solu.search([1], 1))


if __name__ == "__main__":
    main()
