#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#
# https://leetcode.com/problems/permutations/description/
#
# algorithms
# Medium (54.56%)
# Likes:    1943
# Dislikes: 59
# Total Accepted:    375.1K
# Total Submissions: 682K
# Testcase Example:  '[1,2,3]'
#
# Given a collection of distinct integers, return all possible permutations.
#
# Example:
#
#
# Input: [1,2,3]
# Output:
# [
# ⁠ [1,2,3],
# ⁠ [1,3,2],
# ⁠ [2,1,3],
# ⁠ [2,3,1],
# ⁠ [3,1,2],
# ⁠ [3,2,1]
# ]
#
#
#

from typing import List


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        length = len(nums)
        vis = [0] * length
        result = []

        def dfs(cur):
            nonlocal length
            if len(cur) == length:
                result.append(cur)
                return
            for i in range(length):
                if vis[i] == 1:
                    continue
                vis[i] = 1
                dfs(cur + [nums[i]])
                vis[i] = 0

        dfs([])

        return result


def main():
    solu = Solution()
    print(solu.permute([1, 2, 3]))


if __name__ == "__main__":
    main()
