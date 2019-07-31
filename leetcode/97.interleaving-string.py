#
# @lc app=leetcode id=97 lang=python3
#
# [97] Interleaving String
#
# https://leetcode.com/problems/interleaving-string/description/
#
# algorithms
# Hard (27.72%)
# Likes:    846
# Dislikes: 44
# Total Accepted:    116.8K
# Total Submissions: 410.2K
# Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
#
# Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
# s2.
#
# Example 1:
#
#
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
# Output: true
#
#
# Example 2:
#
#
# Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
# Output: false
#
#
#


class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1 = len(s1)
        l2 = len(s2)
        l3 = len(s3)

        if l1 + l2 != l3 or sorted(s1 + s2) != sorted(s3):
            return False

        # dp[i][j] represents isInterleave(s1[: i], s2[: j], s3[: i+j])
        dp = [[False] * (l2 + 1) for i in range(l1 + 1)]
        dp[0][0] = True

        for i in range(l1 + 1):
            for j in range(l2 + 1):
                if dp[i][j]:
                    if i < l1 and s1[i] == s3[i + j]:
                        dp[i + 1][j] = True
                    if j < l2 and s2[j] == s3[i + j]:
                        dp[i][j + 1] = True

        return dp[l1][l2]


# def main():
#     solu = Solution()
#     print(solu.isInterleave(s1="aabcc", s2="dbbca", s3="aadbbcbcac"))
#     print(solu.isInterleave(s1="aabcc", s2="dbbca", s3="aadbbbaccc"))


# if __name__ == "__main__":
#     main()
