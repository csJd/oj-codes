#
# @lc app=leetcode id=39 lang=python3
#
# [39] Combination Sum
#
# https://leetcode.com/problems/combination-sum/description/
#
# algorithms
# Medium (48.21%)
# Likes:    1928
# Dislikes: 57
# Total Accepted:    336.9K
# Total Submissions: 698.3K
# Testcase Example:  '[2,3,6,7]\n7'
#
# Given a set of candidate numbers (candidates) (without duplicates) and a
# target number (target), find all unique combinations in candidates where the
# candidate numbers sums to target.
#
# The same repeated number may be chosen from candidates unlimited number of
# times.
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
# Input: candidates = [2,3,6,7], target = 7,
# A solution set is:
# [
# ⁠ [7],
# ⁠ [2,2,3]
# ]
#
#
# Example 2:
#
#
# Input: candidates = [2,3,5], target = 8,
# A solution set is:
# [
# [2,2,2,2],
# [2,3,3],
# [3,5]
# ]
#
#
#
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []

        def dfs(pos, arr, remain):
            if remain == 0:
                result.append(arr)
                return
            if pos >= len(candidates):
                return
            num = candidates[pos]
            for t in range(remain//num + 1):
                dfs(pos+1, arr + [num]*t, remain-num*t)
        dfs(0, [], target)

        return result


def main():
    solu = Solution()
    print(solu.combinationSum([2, 3, 5], 8))
    print(solu.combinationSum([2, 3, 6, 7], 7))


if __name__ == "__main__":
    main()
