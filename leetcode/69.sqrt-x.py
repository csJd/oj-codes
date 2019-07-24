#
# @lc app=leetcode id=69 lang=python3
#
# [69] Sqrt(x)
#
# https://leetcode.com/problems/sqrtx/description/
#
# algorithms
# Easy (31.10%)
# Likes:    817
# Dislikes: 1434
# Total Accepted:    390.2K
# Total Submissions: 1.2M
# Testcase Example:  '4'
#
# Implement int sqrt(int x).
#
# Compute and return the square root of x, where x is guaranteed to be a
# non-negative integer.
#
# Since the return type is an integer, the decimal digits are truncated and
# only the integer part of the result is returned.
#
# Example 1:
#
#
# Input: 4
# Output: 2
#
#
# Example 2:
#
#
# Input: 8
# Output: 2
# Explanation: The square root of 8 is 2.82842..., and since
# the decimal part is truncated, 2 is returned.
#
#
#


class Solution:
    def mySqrt(self, x: int) -> int:
        le, ri = 1, x
        while le <= ri:
            mid = (le + ri) >> 1
            if mid * mid > x:
                ri = mid - 1
            else:
                le = mid + 1
        return le - 1
