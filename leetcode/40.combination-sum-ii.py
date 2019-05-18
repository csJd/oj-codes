#
# @lc app=leetcode id=40 lang=python3
#
# [40] Combination Sum II
#
# https://leetcode.com/problems/combination-sum-ii/description/
#
# algorithms
# Medium (41.38%)
# Likes:    810
# Dislikes: 43
# Total Accepted:    218.1K
# Total Submissions: 526.8K
# Testcase Example:  '[10,1,2,7,6,1,5]\n8'
#
# Given a collection of candidate numbers (candidates) and a target number
# (target), find all unique combinations in candidates where the candidate
# numbers sums to target.
#
# Each number in candidates may only be used once in the combination.
#
# Note:
#
#
# All numbers (including target) will be positive integers.
# The solution set must not contain duplicate combinations.
#
#
# Example 1:
#
#
# Input: candidates = [10,1,2,7,6,1,5], target = 8,
# A solution set is:
# [
# ⁠ [1, 7],
# ⁠ [1, 2, 5],
# ⁠ [2, 6],
# ⁠ [1, 1, 6]
# ]
#
#
# Example 2:
#
#
# Input: candidates = [2,5,2,1,2], target = 5,
# A solution set is:
# [
# [1,2,2],
# [5]
# ]
#
#
#
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()  # sorting is helpful to handle duplicates
        result = list()

        def dfs(pos, arr, remain):
            if remain == 0:
                result.append(arr)
                return
            if pos >= len(candidates):
                return

            count = 1
            while pos < len(candidates) - 1 and candidates[pos] == candidates[pos+1]:
                pos += 1
                count += 1
            num = candidates[pos]

            for t in range(count + 1):
                if remain >= num * t:  # this is also important
                    dfs(pos+1, arr + [num]*t, remain-num*t)

        dfs(0, [], target)

        return result


def main():
    solu = Solution()
    print(solu.combinationSum2([14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12], 27))
    print(solu.combinationSum2([2, 5, 2, 1, 2], 5))


if __name__ == "__main__":
    main()
