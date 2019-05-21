#
# @lc app=leetcode id=50 lang=python3
#
# [50] Pow(x, n)
#
# https://leetcode.com/problems/powx-n/description/
#
# algorithms
# Medium (27.83%)
# Likes:    827
# Dislikes: 2048
# Total Accepted:    317.4K
# Total Submissions: 1.1M
# Testcase Example:  '2.00000\n10'
#
# Implement pow(x, n), which calculates x raised to the power n (x^n).
#
# Example 1:
#
#
# Input: 2.00000, 10
# Output: 1024.00000
#
#
# Example 2:
#
#
# Input: 2.10000, 3
# Output: 9.26100
#
#
# Example 3:
#
#
# Input: 2.00000, -2
# Output: 0.25000
# Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
#
#
# Note:
#
#
# -100.0 < x < 100.0
# n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
#
#
#


class Solution:
    def myPow(self, x: float, n: int) -> float:
        sign = 1
        if n < 0:
            n = -n
            sign = -1

        result = 1.0
        while n:
            if n & 1:
                result *= x
            n >>= 1
            x *= x
        if sign < 0:
            result = 1.0 / result
        return result


def main():
    solu = Solution()
    print(solu.myPow(1, 0))


if __name__ == "__main__":
    main()
