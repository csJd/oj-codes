#
# @lc app=leetcode id=79 lang=python3
#
# [79] Word Search
#
# https://leetcode.com/problems/word-search/description/
#
# algorithms
# Medium (30.96%)
# Likes:    1928
# Dislikes: 96
# Total Accepted:    302.6K
# Total Submissions: 951.6K
# Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
#
# Given a 2D board and a word, find if the word exists in the grid.
#
# The word can be constructed from letters of sequentially adjacent cell, where
# "adjacent" cells are those horizontally or vertically neighboring. The same
# letter cell may not be used more than once.
#
# Example:
#
#
# board =
# [
# ⁠ ['A','B','C','E'],
# ⁠ ['S','F','C','S'],
# ⁠ ['A','D','E','E']
# ]
#
# Given word = "ABCCED", return true.
# Given word = "SEE", return true.
# Given word = "ABCB", return false.
#
#
#

from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if len(word) == 0:
            return True
        n_rows = len(board)
        n_cols = len(board[0]) if n_rows > 0 else 0

        vis = [[False] * n_cols for i in range(n_rows)]
        dr = [0, 0, -1, 1]
        dc = [-1, 1, 0, 0]
        flag = False

        def dfs(r, c, k):
            """ use board[r][c] to match word[k]
            """
            nonlocal flag
            if flag or k >= len(word):
                flag = True
                return

            for d in range(4):
                nr = r + dr[d]
                nc = c + dc[d]
                if 0 <= nr < n_rows and 0 <= nc < n_cols and \
                        board[nr][nc] == word[k] and not vis[nr][nc]:
                    vis[nr][nc] = True
                    dfs(nr, nc, k+1)
                    vis[nr][nc] = False

        for i in range(n_rows):
            for j in range(n_cols):
                if board[i][j] == word[0]:
                    vis[i][j] = True
                    dfs(i, j, 1)
                    vis[i][j] = False
                    if flag:
                        return True
        return False


# def main():
#     board = [
#         ['A', 'B', 'C', 'E'],
#         ['S', 'F', 'C', 'S'],
#         ['A', 'D', 'E', 'E']
#     ]
#     solu = Solution()
#     print(solu.exist(board, "ABCCED"))
#     print(solu.exist(board, "SEE"))
#     print(solu.exist(board, "ABAB"))
#     print(solu.exist(board, ""))

#     board = []
#     print(solu.exist(board, "x"))


# if __name__ == "__main__":
#     main()
