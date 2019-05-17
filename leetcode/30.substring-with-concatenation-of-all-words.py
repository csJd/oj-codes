#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
# https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#
# algorithms
# Hard (23.52%)
# Likes:    506
# Dislikes: 865
# Total Accepted:    131.5K
# Total Submissions: 559.3K
# Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
#
# You are given a string, s, and a list of words, words, that are all of the
# same length. Find all starting indices of substring(s) in s that is a
# concatenation of each word in words exactly once and without any intervening
# characters.
#
# Example 1:
#
#
# Input:
# ⁠ s = "barfoothefoobarman",
# ⁠ words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
# respectively.
# The output order does not matter, returning [9,0] is fine too.
#
#
# Example 2:
#
#
# Input:
# ⁠ s = "wordgoodgoodgoodbestword",
# ⁠ words = ["word","good","best","word"]
# Output: []
#
#
#

from collections import defaultdict
from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        ans = list()
        if len(words) == 0:
            return []
        word_len = len(words[0])
        n_words = len(words)
        word_counts = defaultdict(int)
        for word in words:
            word_counts[word] += 1

        for i in range(len(s) - n_words * word_len + 1):
            tmp_counts = defaultdict(int)
            for j in range(n_words):
                start = i + j*word_len
                word = s[start:start+word_len]
                if word not in word_counts:
                    break
                tmp_counts[word] += 1
            else:  # not break
                if word_counts == tmp_counts:
                    ans.append(i)
        return ans


def main():
    solu = Solution()
    print(solu.findSubstring("barfoothefoobarman", ["foo", "bar"]))


if __name__ == "__main__":
    main()
