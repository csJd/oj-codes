#
# @lc app=leetcode id=74 lang=python3
#
# [74] Search a 2D Matrix
#
# https://leetcode.com/problems/search-a-2d-matrix/description/
#
# algorithms
# Medium (34.80%)
# Likes:    912
# Dislikes: 108
# Total Accepted:    235.1K
# Total Submissions: 671K
# Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
#
# Write an efficient algorithm that searches for a value in an m x n matrix.
# This matrix has the following properties:
#
#
# Integers in each row are sorted from left to right.
# The first integer of each row is greater than the last integer of the
# previous row.
#
#
# Example 1:
#
#
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 3
# Output: true
#
#
# Example 2:
#
#
# Input:
# matrix = [
# ⁠ [1,   3,  5,  7],
# ⁠ [10, 11, 16, 20],
# ⁠ [23, 30, 34, 50]
# ]
# target = 13
# Output: false
#
#


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n_rows = len(matrix)
        n_cols = len(matrix[0]) if n_rows else 0
        if n_rows == 0 or n_cols == 0:
            return False

        le, ri = 0, n_rows - 1
        while le <= ri:
            mid = (le + ri) >> 1
            if matrix[mid][0] > target:
                ri = mid - 1
            elif matrix[mid][-1] < target:
                le = mid + 1
            else:
                break

        arr = matrix[mid]
        le, ri = 0, n_cols-1
        while le <= ri:
            mid = (le + ri) >> 1
            if arr[mid] > target:
                ri = mid - 1
            elif arr[mid] < target:
                le = mid + 1
            else:
                return True

        return False
