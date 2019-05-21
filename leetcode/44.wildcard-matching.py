#
# @lc app=leetcode id=44 lang=python3
#
# [44] Wildcard Matching
#
# https://leetcode.com/problems/wildcard-matching/description/
#
# algorithms
# Hard (22.67%)
# Likes:    1028
# Dislikes: 71
# Total Accepted:    175.2K
# Total Submissions: 769K
# Testcase Example:  '"aa"\n"a"'
#
# Given an input string (s) and a pattern (p), implement wildcard pattern
# matching with support for '?' and '*'.
#
#
# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# s could be empty and contains only lowercase letters a-z.
# p could be empty and contains only lowercase letters a-z, and characters like
# ? or *.
#
#
# Example 1:
#
#
# Input:
# s = "aa"
# p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
#
#
# Example 2:
#
#
# Input:
# s = "aa"
# p = "*"
# Output: true
# Explanation: '*' matches any sequence.
#
#
# Example 3:
#
#
# Input:
# s = "cb"
# p = "?a"
# Output: false
# Explanation: '?' matches 'c', but the second letter is 'a', which does not
# match 'b'.
#
#
# Example 4:
#
#
# Input:
# s = "adceb"
# p = "*a*b"
# Output: true
# Explanation: The first '*' matches the empty sequence, while the second '*'
# matches the substring "dce".
#
#
# Example 5:
#
#
# Input:
# s = "acdcb"
# p = "a*c?b"
# Output: false
#
#
#


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s, p = " " + s, " " + p
        slen, plen = len(s), len(p)
        # match[i][j] refers to s[:i+1] matches p[:j+1]
        match = [[False] * plen for i in range(slen)]
        match[0][0] = True
        for j in range(1, plen):
            tmp = False  # to save OR(match[0:i][j-1])
            for i in range(0, slen):
                tmp = tmp or match[i][j-1]
                if i > 0 and (p[j] == '?' or s[i] == p[j]):
                    match[i][j] = match[i-1][j-1]
                if p[j] == '*':
                    match[i][j] = tmp  # match[0:i][j-1]
        return match[slen-1][plen-1]


def main():
    solu = Solution()
    print(solu.isMatch("", "**"))
    print(solu.isMatch("acdeb", "*a*b"))
    print(solu.isMatch("acdcb", "a*c?b"))


if __name__ == "__main__":
    main()
