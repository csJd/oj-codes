#
# @lc app=leetcode id=77 lang=python3
#
# [77] Combinations
#
# https://leetcode.com/problems/combinations/description/
#
# algorithms
# Medium (47.07%)
# Likes:    836
# Dislikes: 48
# Total Accepted:    213.5K
# Total Submissions: 438.9K
# Testcase Example:  '4\n2'
#
# Given two integers n and k, return all possible combinations of k numbers out
# of 1 ... n.
#
# Example:
#
#
# Input: n = 4, k = 2
# Output:
# [
# ⁠ [2,4],
# ⁠ [3,4],
# ⁠ [2,3],
# ⁠ [1,2],
# ⁠ [1,3],
# ⁠ [1,4],
# ]
#
#
#


from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        if n < k:
            return list()

        result = list()

        def dfs(cur):
            if len(cur) == k:
                result.append(cur)
                return
            start = 1 if len(cur) == 0 else cur[-1] + 1
            for i in range(start, n+1):
                dfs(cur + [i])

        dfs([])

        return result


# def main():
#     solu = Solution()
#     print(solu.combine(4, 4))


# if __name__ == "__main__":
#     main()
