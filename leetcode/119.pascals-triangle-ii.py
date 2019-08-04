#
# @lc app=leetcode id=119 lang=python3
#
# [119] Pascal's Triangle II
#
# https://leetcode.com/problems/pascals-triangle-ii/description/
#
# algorithms
# Easy (44.56%)
# Likes:    526
# Dislikes: 172
# Total Accepted:    216.2K
# Total Submissions: 485.3K
# Testcase Example:  '3'
#
# Given a non-negative index k where k ≤ 33, return the k^th index row of the
# Pascal's triangle.
#
# Note that the row index starts from 0.
#
#
# In Pascal's triangle, each number is the sum of the two numbers directly
# above it.
#
# Example:
#
#
# Input: 3
# Output: [1,3,3,1]
#
#
# Follow up:
#
# Could you optimize your algorithm to use only O(k) extra space?
#
#

from typing import List


class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        if rowIndex == 0:
            return [1]
        arr = [1, 1]
        for i in range(1, rowIndex):
            for j in range(i):
                arr[j] += arr[j+1]
            arr.insert(0, 1)
        return arr


# def main():
#     solu = Solution()
#     print(solu.getRow(2))
#     print(solu.getRow(3))


# if __name__ == "__main__":
#     main()
