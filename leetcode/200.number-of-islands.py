#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#
# https://leetcode.com/problems/number-of-islands/description/
#
# algorithms
# Medium (42.44%)
# Likes:    3003
# Dislikes: 109
# Total Accepted:    406.8K
# Total Submissions: 955.8K
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# Given a 2d grid map of '1's (land) and '0's (water), count the number of
# islands. An island is surrounded by water and is formed by connecting
# adjacent lands horizontally or vertically. You may assume all four edges of
# the grid are all surrounded by water.
#
# Example 1:
#
#
# Input:
# 11110
# 11010
# 11000
# 00000
#
# Output: 1
#
#
# Example 2:
#
#
# Input:
# 11000
# 11000
# 00100
# 00011
#
# Output: 3
#
#


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if (not grid) or (not grid[0]):
            return 0

        n, m = len(grid), len(grid[0])
        direc = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def dfs(r, c):
            grid[r][c] = '0'
            for dx, dy in direc:
                nr = r + dx
                nc = c + dy
                if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] != '0':
                    dfs(nr, nc)

        ans = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    ans += 1
                    dfs(i, j)

        return ans
