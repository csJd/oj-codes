#
# @lc app=leetcode id=174 lang=python3
#
# [174] Dungeon Game
#
# https://leetcode.com/problems/dungeon-game/description/
#
# algorithms
# Hard (27.66%)
# Likes:    767
# Dislikes: 18
# Total Accepted:    69.9K
# Total Submissions: 252.2K
# Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
#
# table.dungeon, .dungeon th, .dungeon td {
# ⁠ border:3px solid black;
# }
#
# ⁠.dungeon th, .dungeon td {
# ⁠   text-align: center;
# ⁠   height: 70px;
# ⁠   width: 70px;
# }
#
# The demons had captured the princess (P) and imprisoned her in the
# bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
# out in a 2D grid. Our valiant knight (K) was initially positioned in the
# top-left room and must fight his way through the dungeon to rescue the
# princess.
#
# The knight has an initial health point represented by a positive integer. If
# at any point his health point drops to 0 or below, he dies immediately.
#
# Some of the rooms are guarded by demons, so the knight loses health (negative
# integers) upon entering these rooms; other rooms are either empty (0's) or
# contain magic orbs that increase the knight's health (positive integers).
#
# In order to reach the princess as quickly as possible, the knight decides to
# move only rightward or downward in each step.
#
#
#
# Write a function to determine the knight's minimum initial health so that he
# is able to rescue the princess.
#
# For example, given the dungeon below, the initial health of the knight must
# be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN ->
# DOWN.
#
#
#
#
# -2 (K)
# -3
# 3
#
#
# -5
# -10
# 1
#
#
# 10
# 30
# -5 (P)
#
#
#
#
#
#
# Note:
#
#
# The knight's health has no upper bound.
# Any room can contain threats or power-ups, even the first room the knight
# enters and the bottom-right room where the princess is imprisoned.
#
#
#

from typing import List


class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        # dp[i][j] represents hp required starting from (i,j) to (n-1,m-1)
        inf = 1 << 64
        dp = [inf] * (m+1)
        dp[m-1] = 1  # cannot be dp[m] = 1
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                # dp[j+1] is dp[i][j+1] and dp[j] is dp[i+1][j] here
                dp[j] = max(1, -dungeon[i][j] + min(dp[j], dp[j+1]))

        return dp[0]

    def calculateMinimumHP2D(self, dungeon: List[List[int]]) -> int:
        n, m = len(dungeon), len(dungeon[0])
        # dp[i][j] represents hp required starting from (i,j) to (n-1,m-1)
        inf = 1 << 64
        dp = [[inf] * (m+1) for i in range(n+1)]
        dp[n][m-1] = 1
        for i in range(n-1, -1, -1):
            for j in range(m-1, -1, -1):
                dp[i][j] = max(1, -dungeon[i][j] + min(dp[i+1][j], dp[i][j+1]))
        return dp[0][0]


def main():
    solu = Solution()
    print(solu.calculateMinimumHP([
        [-2, -3, 3],
        [-5, -10, 1],
        [10, 30, -5]
    ]))

    print(solu.calculateMinimumHP([
        [1, -3, 3],
        [0, -2, 0],
        [-3, -3, -3]
    ]))


if __name__ == "__main__":
    main()
