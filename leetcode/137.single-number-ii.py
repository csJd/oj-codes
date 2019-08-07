#
# @lc app=leetcode id=137 lang=python3
#
# [137] Single Number II
#
# https://leetcode.com/problems/single-number-ii/description/
#
# algorithms
# Medium (45.65%)
# Likes:    893
# Dislikes: 266
# Total Accepted:    174K
# Total Submissions: 373.4K
# Testcase Example:  '[2,2,3,2]'
#
# Given a non-empty array of integers, every element appears three times except
# for one, which appears exactly once. Find that single one.
#
# Note:
#
# Your algorithm should have a linear runtime complexity. Could you implement
# it without using extra memory?
#
# Example 1:
#
#
# Input: [2,2,3,2]
# Output: 3
#
#
# Example 2:
#
#
# Input: [0,1,0,1,0,1,99]
# Output: 99
#
#

from typing import List

"""
Xor solution

       a, b
       0, 0
x-1st  x, 0
x-2ed  0, x
x-3rd  0, 0
"""


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        a, b = 0, 0
        for num in nums:
            a = a ^ num & (~b)
            b = b ^ num & (~a)
        return a


# def main():
#     solu = Solution()
#     print(solu.singleNumber([0, 1, 0, 1, 0, 1, 99]))


# if __name__ == "__main__":
#     main()
