#
# @lc app=leetcode id=126 lang=python3
#
# [126] Word Ladder II
#
# https://leetcode.com/problems/word-ladder-ii/description/
#
# algorithms
# Hard (18.32%)
# Likes:    1053
# Dislikes: 197
# Total Accepted:    128.6K
# Total Submissions: 701.4K
# Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
#
# Given two words (beginWord and endWord), and a dictionary's word list, find
# all shortest transformation sequence(s) from beginWord to endWord, such
# that:
#
#
# Only one letter can be changed at a time
# Each transformed word must exist in the word list. Note that beginWord is not
# a transformed word.
#
#
# Note:
#
#
# Return an empty list if there is no such transformation sequence.
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
# Output:
# [
# ⁠ ["hit","hot","dot","dog","cog"],
# ["hit","hot","lot","log","cog"]
# ]
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
# Output: []
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
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList:
            return []
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
        tranformations = [[] for i in range(n_words+1)]
        d = [-1] * (n_words + 1)
        d[n_words] = 0
        queue = [n_words]
        while queue:
            i = queue.pop(0)
            for j in range(word_length):
                trans = wordList[i][:j] + '*' + wordList[i][j+1:]
                for k in next_words[trans]:
                    if (d[k] == -1 or d[k] == d[i]+1):
                        if d[k] == -1:
                            queue.append(k)
                            d[k] = d[i] + 1
                    tranformations[i].append(k)

        result = []

        vis = [False] * (n_words + 1)

        def dfs(i, seq, k):
            if k > d[i]:
                return
            if seq[-1] == endWord:
                result.append(seq)
                return
            vis[i] = True
            for j in tranformations[i]:
                if not vis[j]:
                    dfs(j, seq+[wordList[j]], k+1)
            vis[i] = False

        dfs(n_words, [beginWord], 0)
        wordList.pop()
        return result


# def main():
#     solu = Solution()
#     beginWord = "hit"
#     endWord = "cog"
#     wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
#     print(solu.findLadders(beginWord, endWord, wordList))

#     beginWord = "hit"
#     endWord = "cog"
#     wordList = ["hot", "dot", "dog", "lot", "log"]
#     print(solu.findLadders(beginWord, endWord, wordList))


# if __name__ == "__main__":
#     main()
