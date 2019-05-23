#
# @lc app=leetcode id=51 lang=python3
#
# [51] N-Queens
#
# https://leetcode.com/problems/n-queens/description/
#
# algorithms
# Hard (38.70%)
# Likes:    892
# Dislikes: 42
# Total Accepted:    140.1K
# Total Submissions: 358K
# Testcase Example:  '4'
#
# The n-queens puzzle is the problem of placing n queens on an n×n chessboard
# such that no two queens attack each other.
#
#
#
# Given an integer n, return all distinct solutions to the n-queens puzzle.
#
# Each solution contains a distinct board configuration of the n-queens'
# placement, where 'Q' and '.' both indicate a queen and an empty space
# respectively.
#
# Example:
#
#
# Input: 4
# Output: [
# ⁠[".Q..",  // Solution 1
# ⁠ "...Q",
# ⁠ "Q...",
# ⁠ "..Q."],
#
# ⁠["..Q.",  // Solution 2
# ⁠ "Q...",
# ⁠ "...Q",
# ⁠ ".Q.."]
# ]
# Explanation: There exist two distinct solutions to the 4-queens puzzle as
# shown above.
#
#
#

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        board = [['.'] * n for i in range(n)]
        vis = [[False] * (2*n) for i in range(3)]  # col, main, secondary

        result = []

        def dfs(r):  # search every row
            if r >= n:
                output = [''.join([board[i][j] for j in range(n)])
                          for i in range(n)]
                result.append(output)
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
    for res in solu.solveNQueens(4):
        print(res)


if __name__ == "__main__":
    main()
