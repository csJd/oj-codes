#
# @lc app=leetcode id=132 lang=python3
#
# [132] Palindrome Partitioning II
#
# https://leetcode.com/problems/palindrome-partitioning-ii/description/
#
# algorithms
# Hard (27.11%)
# Likes:    654
# Dislikes: 24
# Total Accepted:    107.6K
# Total Submissions: 385.2K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
#
# Return the minimum cuts needed for a palindrome partitioning of s.
#
# Example:
#
#
# Input: "aab"
# Output: 1
# Explanation: The palindrome partitioning ["aa","b"] could be produced using 1
# cut.
#
#
#


class Solution:
    def minCut(self, s: str) -> int:
        length = len(s)
        is_pal = [[False] * length for i in range(length)]
        dp = [-1] * length  # dp[j] for minCut(s[:j+1])

        for j in range(length):
            dp[j] = j
            for i in range(j+1):
                # s[i:j+1] is a palindrome
                if s[i] == s[j] and (i+1 > j-1 or is_pal[i+1][j-1]):
                    is_pal[i][j] = True
                    dp[j] = 0 if i == 0 else min(dp[j], dp[i-1]+1)

        return dp[length-1]


# def main():
#     solu = Solution()
#     print(solu.minCut("aab"))


# if __name__ == "__main__":
#     main()
