#
# @lc app=leetcode id=118 lang=python3
#
# [118] Pascal's Triangle
#
# https://leetcode.com/problems/pascals-triangle/description/
#
# algorithms
# Easy (47.09%)
# Likes:    789
# Dislikes: 80
# Total Accepted:    271.9K
# Total Submissions: 577.3K
# Testcase Example:  '5'
#
# Given a non-negative integer numRows, generate the first numRows of Pascal's
# triangle.
#
#
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
#
# Example:
#
#
# Input: 5
# Output:
# [
# ⁠    [1],
# ⁠   [1,1],
# ⁠  [1,2,1],
# ⁠ [1,3,3,1],
# ⁠[1,4,6,4,1]
# ]
#
#
#
from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = [[1], [1, 1]]
        for i in range(2, numRows):
            arr = [1]
            for j in range(1, i):
                arr.append(result[-1][j] + result[-1][j-1])
            arr.append(1)
            result.append(arr)
        return result[:numRows]


# def main():
#     solu = Solution()
#     print(solu.generate(5))


# if __name__ == "__main__":
#     main()
