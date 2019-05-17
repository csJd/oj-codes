#
# @lc app=leetcode id=32 lang=python3
#
# [32] Longest Valid Parentheses
#
# https://leetcode.com/problems/longest-valid-parentheses/description/
#
# algorithms
# Hard (25.40%)
# Likes:    1785
# Dislikes: 86
# Total Accepted:    187.7K
# Total Submissions: 738.9K
# Testcase Example:  '"(()"'
#
# Given a string containing just the characters '(' and ')', find the length of
# the longest valid (well-formed) parentheses substring.
#
# Example 1:
#
#
# Input: "(()"
# Output: 2
# Explanation: The longest valid parentheses substring is "()"
#
#
# Example 2:
#
#
# Input: ")()())"
# Output: 4
# Explanation: The longest valid parentheses substring is "()()"
#
#
#


class Solution:
    def longestValidParentheses(self, s: str) -> int:
        length = len(s)
        dp = [0 for i in range(length)]
        ans = 0
        for i in range(1, length):
            if s[i] == '(':
                continue
            if s[i-1] == '(':  # append ()
                dp[i] = dp[i-2] + 2  # dp[-1] = 0 when i = 1
            elif i - 1 - dp[i-1] >= 0 and s[i-1-dp[i-1]] == '(':  # surround ()
                dp[i] = dp[i-1] + 2 + dp[i-2-dp[i-1]]
            if dp[i] > ans:
                ans = dp[i]
        return ans


def main():
    solu = Solution()
    print(solu.longestValidParentheses(")()())"))  # 4
    print(solu.longestValidParentheses("()(())"))  # 6


if __name__ == "__main__":
    main()
