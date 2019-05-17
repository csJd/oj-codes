#
# @lc app=leetcode id=37 lang=python3
#
# [37] Sudoku Solver
#
# https://leetcode.com/problems/sudoku-solver/description/
#
# algorithms
# Hard (36.67%)
# Likes:    831
# Dislikes: 56
# Total Accepted:    127K
# Total Submissions: 346.2K
# Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
#
# Write a program to solve a Sudoku puzzle by filling the empty cells.
#
# A sudoku solution must satisfy all of the following rules:
#
#
# Each of the digits 1-9 must occur exactly once in each row.
# Each of the digits 1-9 must occur exactly once in each column.
# Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
# sub-boxes of the grid.
#
#
# Empty cells are indicated by the character '.'.
#
#
# A sudoku puzzle...
#
#
# ...and its solution numbers marked in red.
#
# Note:
#
#
# The given board contain only digits 1-9 and the character '.'.
# You may assume that the given Sudoku puzzle will have a single unique
# solution.
# The given board size is always 9x9.
#
#
#
from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def get_id(r, c):
            '''get corresponding bitmap id of row, column and box'''
            box_id = 18 + r // 3 * 3 + c // 3
            return [r, 9+c, box_id]

        vis = [0 for i in range(27)]
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':
                    continue
                val = int(board[r][c])
                # use bitmap to record
                for id in get_id(r, c):
                    vis[id] |= 1 << val

        def dfs(r, c):
            ''' solving Sudoku use DFS'''
            if r > 8:
                return True
            if board[r][c] != '.':
                return dfs(r + (c+1)//9, (c+1) % 9)
            state = 0
            for id in get_id(r, c):
                state |= vis[id]
            for num in range(1, 10):
                if (1 << num) & state:
                    continue
                # try to fill (r, c) with num
                for id in get_id(r, c):
                    vis[id] |= 1 << num
                board[r][c] = str(num)
                solved = dfs(r + (c+1)//9, (c+1) % 9)
                if solved:
                    return True

                # not solved, backtracking
                for id in get_id(r, c):
                    vis[id] ^= 1 << num
                board[r][c] = '.'

        dfs(0, 0)


def main():
    board = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"]
    ]
    solu = Solution()
    solu.solveSudoku(board)
    for row in board:
        print(row)


if __name__ == "__main__":
    main()
