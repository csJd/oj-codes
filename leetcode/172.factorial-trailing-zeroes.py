#
# @lc app=leetcode id=172 lang=python3
#
# [172] Factorial Trailing Zeroes
#
# https://leetcode.com/problems/factorial-trailing-zeroes/description/
#
# algorithms
# Easy (37.53%)
# Likes:    531
# Dislikes: 765
# Total Accepted:    166.7K
# Total Submissions: 444K
# Testcase Example:  '3'
#
# Given an integer n, return the number of trailing zeroes in n!.
#
# Example 1:
#
#
# Input: 3
# Output: 0
# Explanation: 3! = 6, no trailing zero.
#
# Example 2:
#
#
# Input: 5
# Output: 1
# Explanation: 5! = 120, one trailing zero.
#
# Note: Your solution should be in logarithmic time complexity.
#
#


class Solution:
    def trailingZeroes(self, n: int) -> int:
        # count the number of prime 5 in the result of n!
        cnt5 = 0
        base = 5
        while n >= base:
            cnt5 += n // base
            base *= 5

        return cnt5


def main():
    solu = Solution()
    print(solu.trailingZeroes(5))
    print(solu.trailingZeroes(15))


if __name__ == "__main__":
    main()
