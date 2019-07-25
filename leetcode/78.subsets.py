#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#
# https://leetcode.com/problems/subsets/description/
#
# algorithms
# Medium (52.19%)
# Likes:    2123
# Dislikes: 53
# Total Accepted:    388.6K
# Total Submissions: 721K
# Testcase Example:  '[1,2,3]'
#
# Given a set of distinct integers, nums, return all possible subsets (the
# power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# Example:
#
#
# Input: nums = [1,2,3]
# Output:
# [
#  [3],
#  [1],
#  [2],
#  [1,2,3],
#  [1,3],
#  [2,3],
#  [1,2],
#  []
# ]
#
#

from typing import List
from itertools import combinations


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = [[]]
        n_nums = len(nums)
        nrange = range(n_nums)

        for i in range(1, n_nums + 1):
            for indice in combinations(nrange, i):
                cur = [nums[j] for j in indice]
                result.append(cur)

        return result


# def main():
#     solu = Solution()
#     print(solu.subsets([1, 2, 3]))


# if __name__ == "__main__":
#     main()
