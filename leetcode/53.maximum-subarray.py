#
# @lc app=leetcode id=53 lang=python3
#
# [53] Maximum Subarray
#
# https://leetcode.com/problems/maximum-subarray/description/
#
# algorithms
# Easy (43.48%)
# Likes:    4206
# Dislikes: 145
# Total Accepted:    524.5K
# Total Submissions: 1.2M
# Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
#
# Given an integer array nums, find the contiguous subarray (containing at
# least one number) which has the largest sum and return its sum.
#
# Example:
#
#
# Input: [-2,1,-3,4,-1,2,1,-5,4],
# Output: 6
# Explanation: [4,-1,2,1] has the largest sum = 6.
#
#
# Follow up:
#
# If you have figured out the O(n) solution, try coding another solution using
# the divide and conquer approach, which is more subtle.
#
#


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0
        result = nums[0] if nums else 0  # nums can be all negative
        for num in nums:
            sum += num
            if sum > result:
                result = sum
            if sum < 0:
                sum = 0
        return result
