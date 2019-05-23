#
# @lc app=leetcode id=54 lang=python3
#
# [54] Spiral Matrix
#
# https://leetcode.com/problems/spiral-matrix/description/
#
# algorithms
# Medium (30.14%)
# Likes:    1055
# Dislikes: 403
# Total Accepted:    231.8K
# Total Submissions: 763.1K
# Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
#
# Given a matrix of m x n elements (m rows, n columns), return all elements of
# the matrix in spiral order.
#
# Example 1:
#
#
# Input:
# [
# ⁠[ 1, 2, 3 ],
# ⁠[ 4, 5, 6 ],
# ⁠[ 7, 8, 9 ]
# ]
# Output: [1,2,3,6,9,8,7,4,5]
#
#
# Example 2:
#
# Input:
# [
# ⁠ [1, 2, 3, 4],
# ⁠ [5, 6, 7, 8],
# ⁠ [9,10,11,12]
# ]
# Output: [1,2,3,4,8,12,11,10,9,5,6,7]
#
#
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m = len(matrix)
        n = len(matrix[0]) if m > 0 else 0
        d, r, c = 0, 0, 0
        result = []

        def get_value(r, c):
            if 0 <= r < m and 0 <= c < n:
                return matrix[r][c]
            return None

        while get_value(r, c) is not None:
            result.append(matrix[r][c])
            matrix[r][c] = None
            if get_value(r+directions[d][0], c + directions[d][1]) is None:
                d = (d+1) % 4
            r, c = r+directions[d][0], c + directions[d][1]

        return result


def main():
    solu = Solution()
    # m = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    m = []
    print(solu.spiralOrder(m))


if __name__ == "__main__":
    main()
