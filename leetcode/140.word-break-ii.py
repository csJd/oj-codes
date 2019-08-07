#
# @lc app=leetcode id=140 lang=python3
#
# [140] Word Break II
#
# https://leetcode.com/problems/word-break-ii/description/
#
# algorithms
# Hard (27.08%)
# Likes:    1068
# Dislikes: 257
# Total Accepted:    167.7K
# Total Submissions: 602.3K
# Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
#
# Given a non-empty string s and a dictionary wordDict containing a list of
# non-empty words, add spaces in s to construct a sentence where each word is a
# valid dictionary word. Return all such possible sentences.
#
# Note:
#
#
# The same word in the dictionary may be reused multiple times in the
# segmentation.
# You may assume the dictionary does not contain duplicate words.
#
#
# Example 1:
#
#
# Input:
# s = "catsanddog"
# wordDict = ["cat", "cats", "and", "sand", "dog"]
# Output:
# [
# "cats and dog",
# "cat sand dog"
# ]
#
#
# Example 2:
#
#
# Input:
# s = "pineapplepenapple"
# wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
# Output:
# [
# "pine apple pen apple",
# "pineapple pen apple",
# "pine applepen apple"
# ]
# Explanation: Note that you are allowed to reuse a dictionary word.
#
#
# Example 3:
#
#
# Input:
# s = "catsandog"
# wordDict = ["cats", "dog", "sand", "and", "cat"]
# Output:
# []
#
#


from typing import List


class Solution:

    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        length = len(s)

        dp = [False] * (length+1)
        # dp[i] represents to wordBreak(s[:i], wordDict)
        dp[0] = True
        for i in range(length):
            if dp[i]:
                for word in wordDict:
                    if(s[i:i+len(word)] == word):
                        dp[i+len(word)] = True
        if not dp[length]:
            return []

        def dfs(cur, pos):
            if pos == length:
                result.append(" ".join(cur))
                return
            for word in wordDict:
                if s[pos:pos+len(word)] == word:
                    dfs(cur+[word], pos+len(word))

        result = []
        dfs([], 0)
        return result

    # TLE Solution
    def wordBreak1(self, s: str, wordDict: List[str]) -> List[str]:
        length = len(s)

        dp = [list() for i in range(length + 1)]
        dp[0].append([])
        for i in range(length+1):
            # dp[i] not empty
            if not dp[i]:
                continue
            for word in wordDict:
                right = i + len(word)
                if s[i:right] == word:
                    for brk in dp[i]:
                        dp[right].append(brk+[word])
            if i < length:
                dp[i].clear()

        result = [" ".join(brk) for brk in dp[length]]

        return result

# def main():
#     solu = Solution()
#     print(solu.wordBreak(s="pineapplepenapple", wordDict=[
#           "apple", "pen", "applepen", "pine", "pineapple"]))
#     print(solu.wordBreak(
#         s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
#         "aaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa"
#         "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
#         wordDict=["a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
#                   "aaaaaaa", "aaaaaaaa", "aaaaaaaaa",
#                   "aaaaaaaaaa"]
#     ))


# if __name__ == "__main__":
#     main()
