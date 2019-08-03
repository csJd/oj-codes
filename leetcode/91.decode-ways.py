#
# @lc app=leetcode id=91 lang=python3
#
# [91] Decode Ways
#
# https://leetcode.com/problems/decode-ways/description/
#
# algorithms
# Medium (22.16%)
# Likes:    1506
# Dislikes: 1751
# Total Accepted:    276.1K
# Total Submissions: 1.2M
# Testcase Example:  '"12"'
#
# A message containing letters from A-Z is being encoded to numbers using the
# following mapping:
#
#
# 'A' -> 1
# 'B' -> 2
# ...
# 'Z' -> 26
#
#
# Given a non-empty string containing only digits, determine the total number
# of ways to decode it.
#
# Example 1:
#
#
# Input: "12"
# Output: 2
# Explanation: It could be decoded as "AB" (1 2) or "L" (12).
#
#
# Example 2:
#
#
# Input: "226"
# Output: 3
# Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
# 6).
#
#


class Solution:
    def numDecodings(self, s: str) -> int:

        length = len(s)
        dp = [0] * (length+1)  # num_decodings of s[:i]
        dp[0] = 1

        for i in range(1, length+1):

            # can decode s[i-1] alone
            if s[i-1] != '0':
                dp[i] += dp[i-1]

            # can decode s[i-2:i] together
            if i > 1 and (9 < int(s[i-2:i]) < 27):
                dp[i] += dp[i-2]

        return dp[length]


# def main():
#     solu = Solution()
#     print(solu.numDecodings("226"))
#     print(solu.numDecodings("12"))
#     print(solu.numDecodings("01"))  # 0
#     print(solu.numDecodings("10"))
#     print(solu.numDecodings("101"))  # 1


# if __name__ == "__main__":
    # main()
