#
# @lc app=leetcode id=47 lang=python3
#
# [47] Permutations II
#
# https://leetcode.com/problems/permutations-ii/description/
#
# algorithms
# Medium (40.00%)
# Likes:    966
# Dislikes: 43
# Total Accepted:    240.7K
# Total Submissions: 596.4K
# Testcase Example:  '[1,1,2]'
#
# Given a collection of numbers that might contain duplicates, return all
# possible unique permutations.
#
# Example:
#
#
# Input: [1,1,2]
# Output:
# [
# ⁠ [1,1,2],
# ⁠ [1,2,1],
# ⁠ [2,1,1]
# ]
#
#
#

from typing import List
from collections import defaultdict


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        length = len(nums)

        remains = [1]*length
        for i in range(length-1, 0, -1):
            if nums[i] == nums[i-1]:
                remains[i-1] += remains[i]
                remains[i] = 0

        result = []

        def dfs(cur):
            nonlocal length
            if len(cur) == length:
                result.append(cur)
                return
            for i in range(length):
                if remains[i] < 1:
                    continue
                remains[i] -= 1
                dfs(cur + [nums[i]])
                remains[i] += 1

        dfs([])

        return result


def main():
    solu = Solution()
    # print(solu.permuteUnique([1, 1, 3]))
    print(solu.permuteUnique([1]))


if __name__ == "__main__":
    main()
