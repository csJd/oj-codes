#
# @lc app=leetcode id=60 lang=python3
#
# [60] Permutation Sequence
#
# https://leetcode.com/problems/permutation-sequence/description/
#
# algorithms
# Medium (32.79%)
# Likes:    809
# Dislikes: 220
# Total Accepted:    137K
# Total Submissions: 415.1K
# Testcase Example:  '3\n3'
#
# The set [1,2,3,...,n] contains a total of n! unique permutations.
#
# By listing and labeling all of the permutations in order, we get the
# following sequence for n = 3:
#
#
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
#
#
# Given n and k, return the k^th permutation sequence.
#
# Note:
#
#
# Given n will be between 1 and 9 inclusive.
# Given k will be between 1 and n! inclusive.
#
#
# Example 1:
#
#
# Input: n = 3, k = 3
# Output: "213"
#
#
# Example 2:
#
#
# Input: n = 4, k = 9
# Output: "2314"
#
#
#


class Solution:
    def getPermutation(self, n: int, k: int) -> str:

        def factorial(x):
            facl = 1
            for i in range(2, x+1):
                facl *= i
            return facl

        vis = 0
        result = ""
        remains = n
        while remains > 0:
            facl = factorial(remains-1)
            for i in range(1, n+1):
                if vis & 1 << i:
                    continue
                if k > facl:
                    k -= facl
                else:
                    result += str(i)
                    vis = vis | 1 << i
                    remains -= 1
                    break

        return result


def main():
    solu = Solution()
    print(solu.getPermutation(3, 3))
    print(solu.getPermutation(9, 278082))


if __name__ == "__main__":
    main()
