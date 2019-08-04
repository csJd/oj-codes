#
# @lc app=leetcode id=115 lang=python3
#
# [115] Distinct Subsequences
#
# https://leetcode.com/problems/distinct-subsequences/description/
#
# algorithms
# Hard (34.82%)
# Likes:    741
# Dislikes: 38
# Total Accepted:    110.6K
# Total Submissions: 311.9K
# Testcase Example:  '"rabbbit"\n"rabbit"'
#
# Given a string S and a string T, count the number of distinct subsequences of
# S which equals T.
#
# A subsequence of a string is a new string which is formed from the original
# string by deleting some (can be none) of the characters without disturbing
# the relative positions of the remaining characters. (ie, "ACE" is a
# subsequence of "ABCDE" while "AEC" is not).
#
# Example 1:
#
#
# Input: S = "rabbbit", T = "rabbit"
# Output: 3
# Explanation:
#
# As shown below, there are 3 ways you can generate "rabbit" from S.
# (The caret symbol ^ means the chosen letters)
#
# rabbbit
# ^^^^ ^^
# rabbbit
# ^^ ^^^^
# rabbbit
# ^^^ ^^^
#
#
# Example 2:
#
#
# Input: S = "babgbag", T = "bag"
# Output: 5
# Explanation:
#
# As shown below, there are 5 ways you can generate "bag" from S.
# (The caret symbol ^ means the chosen letters)
#
# babgbag
# ^^ ^
# babgbag
# ^^    ^
# babgbag
# ^    ^^
# babgbag
#  ⁠ ^  ^^
# babgbag
#  ⁠   ^^^
#


class Solution:
    # backward dp with Sliding Array
    def numDistinct(self, s: str, t: str) -> int:
        ls = len(s)
        lt = len(t)
        # dp[i][j] for numDistinct(s[:i], t[:j])
        dp = [1] + [0] * lt  # dp[0][0] = 1

        for i in range(1, ls+1):
            # if j > i, dp[i][j] must be zero
            ri = min(lt, i)
            for j in range(ri, 0, -1):
                # dp[j] is dp[i-1][j] here
                if(s[i-1] == t[j-1]):
                    # dp[j-1] here is dp[i-1][j-1] in fact
                    # following equation represents dp[i][j] += dp[i-1][j-1]
                    dp[j] += dp[j-1]

        return dp[lt]  # the value is dp[ls][lt] now

    # backward dp solution
    def numDistinct1(self, s: str, t: str) -> int:
        ls = len(s)
        lt = len(t)
        # dp[i][j] for numDistinct(s[:i], t[:j])
        dp = [[0] * (lt+1) for i in range(ls+1)]
        dp[0][0] = 1
        for i in range(1, ls+1):
            dp[i][0] = 1
            ri = min(lt, i)
            for j in range(1, ri+1):
                dp[i][j] = dp[i-1][j]
                if(s[i-1] == t[j-1]):
                    dp[i][j] += dp[i-1][j-1]

        return dp[ls][lt]

    # forward dp solution
    def numDistinct2(self, s: str, t: str) -> int:
        ls = len(s)
        lt = len(t)
        # dp[i][j] for numDistinct(s[:i], t[:j])
        dp = [[0] * (lt+1) for i in range(ls+1)]
        dp[0][0] = 1
        for i in range(ls):
            for j in range(lt+1):
                if j > i:
                    break
                dp[i+1][j] += dp[i][j]
                if j < lt and s[i] == t[j]:
                    dp[i+1][j+1] += dp[i][j]
        return dp[ls][lt]


# def main():
#     solu = Solution()
#     print(solu.numDistinct("ab", "a"))
#     print(solu.numDistinct("babgbag", "bag"))
#     print(solu.numDistinct("rabbbit", "rabbit"))


# if __name__ == "__main__":
#     main()
