#
# @lc app=leetcode id=125 lang=python3
#
# [125] Valid Palindrome
#
# https://leetcode.com/problems/valid-palindrome/description/
#
# algorithms
# Easy (31.78%)
# Likes:    643
# Dislikes: 1893
# Total Accepted:    383.1K
# Total Submissions: 1.2M
# Testcase Example:  '"A man, a plan, a canal: Panama"'
#
# Given a string, determine if it is a palindrome, considering only
# alphanumeric characters and ignoring cases.
#
# Note: For the purpose of this problem, we define empty string as valid
# palindrome.
#
# Example 1:
#
#
# Input: "A man, a plan, a canal: Panama"
# Output: true
#
#
# Example 2:
#
#
# Input: "race a car"
# Output: false
#
#
#


class Solution:
    def isPalindrome(self, s: str) -> bool:
        le = 0
        ri = len(s) - 1

        while le < ri:
            if not s[le].isalnum():
                le += 1
            elif not s[ri].isalnum():
                ri -= 1
            elif s[le].lower() == s[ri].lower():
                le += 1
                ri -= 1
            else:
                return False

        return True
