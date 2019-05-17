#
# @lc app=leetcode id=36 lang=python3
#
# [36] Valid Sudoku
#
# https://leetcode.com/problems/valid-sudoku/description/
#
# algorithms
# Medium (42.87%)
# Likes:    816
# Dislikes: 300
# Total Accepted:    232.9K
# Total Submissions: 543.2K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
# validated according to the following rules:
#
#
# Each row must contain the digits 1-9 without repetition.
# Each column must contain the digits 1-9 without repetition.
# Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
# repetition.
#
#
#
# A partially filled sudoku which is valid.
#
# The Sudoku board could be partially filled, where empty cells are filled with
# the character '.'.
#
# Example 1:
#
#
# Input:
# [
# ⁠ ["5","3",".",".","7",".",".",".","."],
# ⁠ ["6",".",".","1","9","5",".",".","."],
# ⁠ [".","9","8",".",".",".",".","6","."],
# ⁠ ["8",".",".",".","6",".",".",".","3"],
# ⁠ ["4",".",".","8",".","3",".",".","1"],
# ⁠ ["7",".",".",".","2",".",".",".","6"],
# ⁠ [".","6",".",".",".",".","2","8","."],
# ⁠ [".",".",".","4","1","9",".",".","5"],
# ⁠ [".",".",".",".","8",".",".","7","9"]
# ]
# Output: true
#
#
# Example 2:
#
#
# Input:
# [
# ["8","3",".",".","7",".",".",".","."],
# ["6",".",".","1","9","5",".",".","."],
# [".","9","8",".",".",".",".","6","."],
# ["8",".",".",".","6",".",".",".","3"],
# ["4",".",".","8",".","3",".",".","1"],
# ["7",".",".",".","2",".",".",".","6"],
# [".","6",".",".",".",".","2","8","."],
# [".",".",".","4","1","9",".",".","5"],
# [".",".",".",".","8",".",".","7","9"]
# ]
# Output: false
# Explanation: Same as Example 1, except with the 5 in the top left corner
# being
# ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is
# invalid.
#
#
# Note:
#
#
# A Sudoku board (partially filled) could be valid but is not necessarily
# solvable.
# Only the filled cells need to be validated according to the mentioned
# rules.
# The given board contain only digits 1-9 and the character '.'.
# The given board size is always 9x9.
#
#
#


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        vis = 0

        def valid_array(arr):
            vis = 0
            for num in arr:
                if vis & (1 << num):
                    return False
                vis = vis | (1 << num)
            return True

        for r in range(9):
            arr = [int(x) for x in board[r] if x != '.']
            if not valid_array(arr):
                return False

        for c in range(9):
            arr = [int(board[r][c]) for r in range(9) if board[r][c] != '.']
            if not valid_array(arr):
                return False

        for r in [0, 3, 6]:
            for c in [0, 3, 6]:
                arr = [int(board[r+dx][c+dy]) for dx in range(3)
                       for dy in range(3) if board[r+dx][c+dy] != '.']
                if not valid_array(arr):
                    return False
        return True
