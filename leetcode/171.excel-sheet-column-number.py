#
# @lc app=leetcode id=171 lang=python3
#
# [171] Excel Sheet Column Number
#
# https://leetcode.com/problems/excel-sheet-column-number/description/
#
# algorithms
# Easy (52.07%)
# Likes:    596
# Dislikes: 117
# Total Accepted:    233.4K
# Total Submissions: 447.9K
# Testcase Example:  '"A"'
#
# Given a column title as appear in an Excel sheet, return its corresponding
# column number.
#
# For example:
#
#
# ⁠   A -> 1
# ⁠   B -> 2
# ⁠   C -> 3
# ⁠   ...
# ⁠   Z -> 26
# ⁠   AA -> 27
# ⁠   AB -> 28
# ⁠   ...
#
#
# Example 1:
#
#
# Input: "A"
# Output: 1
#
#
# Example 2:
#
#
# Input: "AB"
# Output: 28
#
#
# Example 3:
#
#
# Input: "ZY"
# Output: 701
#
#


class Solution:
    def titleToNumber(self, s: str) -> int:
        base = 1
        ans = 0
        orda = ord('A')
        for i in range(len(s)-1, -1, -1):
            ans += base * (ord(s[i]) - orda + 1)
            base *= 26
        return ans
