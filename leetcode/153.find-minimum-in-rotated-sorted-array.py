#
# @lc app=leetcode id=153 lang=python3
#
# [153] Find Minimum in Rotated Sorted Array
#
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#
# algorithms
# Medium (42.79%)
# Likes:    1111
# Dislikes: 169
# Total Accepted:    305.6K
# Total Submissions: 704.8K
# Testcase Example:  '[3,4,5,1,2]'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
#
# (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
#
# Find the minimum element.
#
# You may assume no duplicate exists in the array.
#
# Example 1:
#
#
# Input: [3,4,5,1,2]
# Output: 1
#
#
# Example 2:
#
#
# Input: [4,5,6,7,0,1,2]
# Output: 0
#
#
#


class Solution:
    def findMin(self, nums: List[int]) -> int:
        length = len(nums)
        le, ri = 0, length - 1
        while(le <= ri):
            mid = (le + ri) >> 1
            if nums[mid] >= nums[0]:  # mid is in the left of pivot
                le = mid + 1
            else:  # mid if in the right of pivot
                ri = mid - 1
        pivot = ri + 1
        if pivot >= length:
            pivot = 0

        return nums[pivot]
