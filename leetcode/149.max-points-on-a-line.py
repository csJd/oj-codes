#
# @lc app=leetcode id=149 lang=python3
#
# [149] Max Points on a Line
#
# https://leetcode.com/problems/max-points-on-a-line/description/
#
# algorithms
# Hard (15.68%)
# Likes:    521
# Dislikes: 1400
# Total Accepted:    125.4K
# Total Submissions: 786K
# Testcase Example:  '[[1,1],[2,2],[3,3]]'
#
# Given n points on a 2D plane, find the maximum number of points that lie on
# the same straight line.
#
# Example 1:
#
#
# Input: [[1,1],[2,2],[3,3]]
# Output: 3
# Explanation:
# ^
# |
# |        o
# |     o
# |  o  
# +------------->
# 0  1  2  3  4
#
#
# Example 2:
#
#
# Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
# Output: 4
# Explanation:
# ^
# |
# |  o
# |     o        o
# |        o
# |  o        o
# +------------------->
# 0  1  2  3  4  5  6
#
#
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
#
#

from collections import defaultdict


class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        if len(points) < 3:
            return len(points)

        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)

        line_points = defaultdict(set)
        n_points = len(points)
        for i in range(n_points):
            x, y = points[i][0], points[i][1]
            for j in range(i):
                dy = y - points[j][1]
                dx = x - points[j][0]
                if dx == 0:
                    dy = 0
                    dxb = points[i][0]
                else:
                    g = gcd(dy, dx)
                    dy, dx = dy//g, dx//g
                    # dy/dx * x + b = y => dy * x + dx * b = dx * y =>
                    # b = (dx * y - dy * x) / dx
                    dxb = dx*y - dy*x
                line_points[(dx, dy, dxb)].add(i)
                line_points[(dx, dy, dxb)].add(j)

        ans = 0
        for line in line_points:
            if len(line_points[line]) > ans:
                ans = len(line_points[line])

        return ans
