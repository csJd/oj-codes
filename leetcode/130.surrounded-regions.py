#
# @lc app=leetcode id=130 lang=python3
#
# [130] Surrounded Regions
#
# https://leetcode.com/problems/surrounded-regions/description/
#
# algorithms
# Medium (22.56%)
# Likes:    838
# Dislikes: 444
# Total Accepted:    154.4K
# Total Submissions: 657.4K
# Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
#
# Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
# surrounded by 'X'.
#
# A region is captured by flipping all 'O's into 'X's in that surrounded
# region.
#
# Example:
#
#
# X X X X
# X O O X
# X X O X
# X O X X
#
#
# After running your function, the board should be:
#
#
# X X X X
# X X X X
# X X X X
# X O X X
#
#
# Explanation:
#
# Surrounded regions shouldn’t be on the border, which means that any 'O' on
# the border of the board are not flipped to 'X'. Any 'O' that is not on the
# border and it is not connected to an 'O' on the border will be flipped to
# 'X'. Two cells are connected if they are adjacent cells connected
# horizontally or vertically.
#
#

from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        dr = [0, 0, -1, 1]
        dc = [-1, 1, 0, 0]

        if (not board) or (not board[0]):
            return
        n = len(board)
        m = len(board[0])
        for i in range(1, n-1):
            for j in range(1, m-1):
                if board[i][j] == 'O':
                    board[i][j] = 'T'

        def dfs(r, c):
            board[r][c] = 'V'  # used as vis dict
            for k in range(4):
                i = r + dr[k]
                j = c + dc[k]
                if 0 <= i < n and 0 <= j < m and board[i][j] in 'OT':
                    dfs(i, j)

        for i in range(n):
            for j in range(m):
                if (i == 0 or i == n-1 or j == 0 or j == m-1) \
                        and board[i][j] == 'O':
                    dfs(i, j)

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'V':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'


# def main():
#     solu = Solution()
#     board = [["O", "O", "O"], ["O", "O", "O"], ["O", "O", "O"]]
#     solu.solve(board)
#     print(board)


# if __name__ == "__main__":
#     main()
