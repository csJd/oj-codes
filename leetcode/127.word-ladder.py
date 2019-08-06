#
# @lc app=leetcode id=127 lang=python3
#
# [127] Word Ladder
#
# https://leetcode.com/problems/word-ladder/description/
#
# algorithms
# Medium (24.86%)
# Likes:    1625
# Dislikes: 853
# Total Accepted:    280.5K
# Total Submissions: 1.1M
# Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
#
# Given two words (beginWord and endWord), and a dictionary's word list, find
# the length of shortest transformation sequence from beginWord to endWord,
# such that:
#
#
# Only one letter can be changed at a time.
# Each transformed word must exist in the word list. Note that beginWord is not
# a transformed word.
#
#
# Note:
#
#
# Return 0 if there is no such transformation sequence.
# All words have the same length.
# All words contain only lowercase alphabetic characters.
# You may assume no duplicates in the word list.
# You may assume beginWord and endWord are non-empty and are not the same.
#
#
# Example 1:
#
#
# Input:
# beginWord = "hit",
# endWord = "cog",
# wordList = ["hot","dot","dog","lot","log","cog"]
#
# Output: 5
#
# Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
# "dog" -> "cog",
# return its length 5.
#
#
# Example 2:
#
#
# Input:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log"]
#
# Output: 0
#
# Explanation: The endWord "cog" is not in wordList, therefore no possible
# transformation.
#
#
#
#
#
#


from typing import List
from collections import defaultdict


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        n_words = len(wordList)
        word_length = len(beginWord)
        wordList.append(beginWord)

        # Preprocessing
        next_words = defaultdict(list)
        for i in range(n_words+1):
            for j in range(word_length):
                trans = wordList[i][:j] + '*' + wordList[i][j+1:]
                next_words[trans].append(i)

        # BFS
        d = [-1] * (n_words + 1)
        d[n_words] = 1
        queue = [n_words]
        while queue:
            i = queue.pop(0)
            for j in range(word_length):
                trans = wordList[i][:j] + '*' + wordList[i][j+1:]
                for k in next_words[trans]:
                    if d[k] == -1:
                        d[k] = d[i] + 1
                        if wordList[k] == endWord:
                            return d[k]
                        queue.append(k)

        wordList.pop()
        return 0


# def main():
#     solu = Solution()
#     beginWord = "hit"
#     endWord = "cog"
#     wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
#     print(solu.ladderLength(beginWord, endWord, wordList))

#     beginWord = "hit"
#     endWord = "cog"
#     wordList = ["hot", "dot", "dog", "lot", "log"]
#     print(solu.ladderLength(beginWord, endWord, wordList))

#     beginWord = "red"
#     endWord = "tax"
#     wordList = ["ted", "tex", "red", "tax", "tad", "den", "rex", "pee"]
#     print(solu.ladderLength(beginWord, endWord, wordList))


# if __name__ == "__main__":
#     main()
