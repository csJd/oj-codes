"""
1162. As Far from Land as Possible
https://leetcode.com/problems/as-far-from-land-as-possible/

Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

If no land or water exists in the grid, return -1.

Example 1:

Input: [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation:
The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:

Input: [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation:
The cell (2, 2) is as far as possible from all the land with distance 4.


Note:

1 <= grid.length == grid[0].length <= 100
grid[i][j] is 0 or 1
"""

from collections import deque


class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        dx = [0, 0, -1, 1]
        dy = [-1, 1, 0, 0]
        n, m = len(grid), len(grid[0])
        land_pos = list()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    land_pos.append((i, j))
                    grid[i][j] = 0
                else:
                    grid[i][j] = n*m

        if not 0 < len(land_pos) < n*m:
            return -1

        for r, c in land_pos:
            queue = deque()
            queue.append((r, c, 0))
            while queue:
                cur_r, cur_c, d = queue.popleft()
                for delta_x, delta_y in zip(dx, dy):
                    nr = cur_r + delta_x
                    nc = cur_c + delta_y
                    if 0 <= nr < n and 0 <= nc < m:
                        if grid[nr][nc] > d+1:
                            grid[nr][nc] = d+1
                            queue.append((nr, nc, grid[nr][nc]))

        ans = 0
        for i in range(n):
            for j in range(m):
                ans = max(ans, grid[i][j])

        return ans
