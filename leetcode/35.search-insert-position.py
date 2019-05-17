#
# @lc app=leetcode id=35 lang=python3
#
# [35] Search Insert Position
#
# https://leetcode.com/problems/search-insert-position/description/
#
# algorithms
# Easy (40.79%)
# Likes:    1270
# Dislikes: 175
# Total Accepted:    395.8K
# Total Submissions: 970.1K
# Testcase Example:  '[1,3,5,6]\n5'
#
# Given a sorted array and a target value, return the index if the target is
# found. If not, return the index where it would be if it were inserted in
# order.
#
# You may assume no duplicates in the array.
#
# Example 1:
#
#
# Input: [1,3,5,6], 5
# Output: 2
#
#
# Example 2:
#
#
# Input: [1,3,5,6], 2
# Output: 1
#
#
# Example 3:
#
#
# Input: [1,3,5,6], 7
# Output: 4
#
#
# Example 4:
#
#
# Input: [1,3,5,6], 0
# Output: 0
#
#
#


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        length = len(nums)
        le, ri = 0, length - 1
        while(le <= ri):
            mid = (le + ri) >> 1
            if nums[mid] < target:
                le = mid + 1
            else:
                ri = mid - 1
        return ri + 1
