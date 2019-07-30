#
# @lc app=leetcode id=90 lang=python3
#
# [90] Subsets II
#
# https://leetcode.com/problems/subsets-ii/description/
#
# algorithms
# Medium (42.05%)
# Likes:    969
# Dislikes: 49
# Total Accepted:    213.4K
# Total Submissions: 495.4K
# Testcase Example:  '[1,2,2]'
#
# Given a collection of integers that might contain duplicates, nums, return
# all possible subsets (the power set).
#
# Note: The solution set must not contain duplicate subsets.
#
# Example:
#
#
# Input: [1,2,2]
# Output:
# [
# ⁠ [2],
# ⁠ [1],
# ⁠ [1,2,2],
# ⁠ [2,2],
# ⁠ [1,2],
# ⁠ []
# ]
#
#
#

from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        cnt_dict = dict()

        for num in nums:
            if num in cnt_dict:
                cnt_dict[num] += 1
            else:
                cnt_dict[num] = 1

        result = list()
        num_set = list(cnt_dict)

        def dfs(pos, cur):
            if pos == len(cnt_dict):
                result.append(cur)
                return

            value = num_set[pos]
            total = cnt_dict[value]

            for i in range(0, total+1):
                dfs(pos+1, cur + [value] * i)

        dfs(0, [])
        return result


# def main():
#     solu = Solution()
#     print(solu.subsetsWithDup([1, 2, 2]))


# if __name__ == "__main__":
#     main()
