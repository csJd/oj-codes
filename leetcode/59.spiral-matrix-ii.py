#
# @lc app=leetcode id=59 lang=python3
#
# [59] Spiral Matrix II
#
# https://leetcode.com/problems/spiral-matrix-ii/description/
#
# algorithms
# Medium (46.11%)
# Likes:    431
# Dislikes: 80
# Total Accepted:    135.5K
# Total Submissions: 291.6K
# Testcase Example:  '3'
#
# Given a positive integer n, generate a square matrix filled with elements
# from 1 to n^2 in spiral order.
#
# Example:
#
#
# Input: 3
# Output:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 8, 9, 4 ],
# ⁠[ 7, 6, 5 ]
# ]
#
#
#
from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        matrix = [[0] * n for i in range(n)]

        def get_value(r, c):
            if 0 <= r < n and 0 <= c < n:
                return matrix[r][c]
            return 1

        count = 0
        d, r, c = 0, 0, 0
        while count < n*n:
            count += 1
            matrix[r][c] = count
            if get_value(r+directions[d][0], c + directions[d][1]) > 0:
                d = (d+1) % 4
            r, c = r+directions[d][0], c + directions[d][1]

        return matrix


def main():
    solu = Solution()
    print(solu.generateMatrix(1))


if __name__ == "__main__":
    main()
