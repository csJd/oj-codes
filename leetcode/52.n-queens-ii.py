#
# @lc app=leetcode id=52 lang=python3
#
# [52] N-Queens II
#
# https://leetcode.com/problems/n-queens-ii/description/
#
# algorithms
# Hard (51.47%)
# Likes:    262
# Dislikes: 107
# Total Accepted:    98.5K
# Total Submissions: 190.2K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
#
#
#
# Given an integer n, return the number of distinct solutions to the n-queens
# puzzle.
#
# Example:
#
#
# Input: 4
# Output: 2
# Explanation: There are two distinct solutions to the 4-queens puzzle as shown
# below.
# [
# [".Q..",  // Solution 1
# "...Q",
# "Q...",
# "..Q."],
#
# ["..Q.",  // Solution 2
# "Q...",
# "...Q",
# ".Q.."]
# ]
#
#
#


class Solution:
    def totalNQueens(self, n: int) -> int:
        board = [['.'] * n for i in range(n)]
        vis = [[False] * (2*n) for i in range(3)]  # col, main, secondary

        result = 0

        def dfs(r):  # search every row
            if r >= n:
                nonlocal result
                result += 1
                return
            for c in range(n):
                if vis[0][c] or vis[1][r+c] or vis[2][r-c+n]:
                    continue
                vis[0][c] = vis[1][r+c] = vis[2][r-c+n] = True
                board[r][c] = 'Q'
                dfs(r+1)
                vis[0][c] = vis[1][r+c] = vis[2][r-c+n] = False
                board[r][c] = '.'
        dfs(0)
        return result


def main():
    solu = Solution()
    print(solu.totalNQueens(8))


if __name__ == "__main__":
    main()
