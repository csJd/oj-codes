#
# @lc app=leetcode id=72 lang=python3
#
# [72] Edit Distance
#
# https://leetcode.com/problems/edit-distance/description/
#
# algorithms
# Hard (37.23%)
# Likes:    2260
# Dislikes: 34
# Total Accepted:    183.7K
# Total Submissions: 477.1K
# Testcase Example:  '"horse"\n"ros"'
#
# Given two words word1 and word2, find the minimum number of operations
# required to convert word1 to word2.
#
# You have the following 3 operations permitted on a word:
#
#
# Insert a character
# Delete a character
# Replace a character
#
#
# Example 1:
#
#
# Input: word1 = "horse", word2 = "ros"
# Output: 3
# Explanation:
# horse -> rorse (replace 'h' with 'r')
# rorse -> rose (remove 'r')
# rose -> ros (remove 'e')
#
#
# Example 2:
#
#
# Input: word1 = "intention", word2 = "execution"
# Output: 5
# Explanation:
# intention -> inention (remove 't')
# inention -> enention (replace 'i' with 'e')
# enention -> exention (replace 'n' with 'x')
# exention -> exection (replace 'n' with 'c')
# exection -> execution (insert 'u')
#
#


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dp[i][j] -> minDistance(word1[:i], word2[:j])
        len1, len2 = len(word1), len(word2)
        dp = [[0] * (len2+1) for i in range(2)]  # 2 * (len2+1) array

        for j in range(len2+1):
            dp[0][j] = j

        for i in range(1, len1+1):
            cur = i % 2
            dp[cur][0] = i
            for j in range(1, len2+1):
                if word1[i-1] == word2[j-1]:
                    dp[cur][j] = dp[cur-1][j-1]
                else:
                    # min(remove, insert, replace)
                    dp[cur][j] = min(dp[cur-1][j], dp[cur]
                                     [j-1], dp[cur-1][j-1]) + 1

        return dp[len1 % 2][len2]


# def main():
#     solu = Solution()
#     print(solu.minDistance('intention', 'execution'))
#     print(solu.minDistance('horse', 'ros'))
#     print(solu.minDistance('', 'ros'))
#     print(solu.minDistance('', ''))


# if __name__ == "__main__":
#     main()
