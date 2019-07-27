#
# @lc app=leetcode id=85 lang=python3
#
# [85] Maximal Rectangle
#
# https://leetcode.com/problems/maximal-rectangle/description/
#
# algorithms
# Hard (33.16%)
# Likes:    1573
# Dislikes: 52
# Total Accepted:    128.2K
# Total Submissions: 377.4K
# Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
#
# Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
# containing only 1's and return its area.
#
# Example:
#
#
# Input:
# [
# ⁠ ["1","0","1","0","0"],
# ⁠ ["1","0","1","1","1"],
# ⁠ ["1","1","1","1","1"],
# ⁠ ["1","0","0","1","0"]
# ]
# Output: 6
#
#
#


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        mono_stack = [(-1, 0)]  # monotonically ascending stack, (index, height)
        largest_area = 0
        for i, h in enumerate(heights + [0]):  # add zero-value element to the last
            right = i - 1
            while h < mono_stack[-1][1]:
                height = mono_stack.pop()[1]
                left = mono_stack[-1][0] + 1
                largest_area = max(largest_area, (right - left + 1) * height)
            mono_stack.append((i, h))

        return largest_area

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        row = [0] * len(matrix[0])
        largest_area = 0
        for i in range(len(matrix)):
            # the i-th row as the bottom line
            for j in range(len(matrix[i])):
                if matrix[i][j] != '0':
                    row[j] += 1
                else:
                    row[j] = 0
            largest_area = max(largest_area, self.largestRectangleArea(row))

        return largest_area
