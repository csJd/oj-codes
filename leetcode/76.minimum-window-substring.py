#
# @lc app=leetcode id=76 lang=python3
#
# [76] Minimum Window Substring
#
# https://leetcode.com/problems/minimum-window-substring/description/
#
# algorithms
# Hard (30.46%)
# Likes:    2474
# Dislikes: 166
# Total Accepted:    252.9K
# Total Submissions: 806.8K
# Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
#
# Given a string S and a string T, find the minimum window in S which will
# contain all the characters in T in complexity O(n).
#
# Example:
#
#
# Input: S = "ADOBECODEBANC", T = "ABC"
# Output: "BANC"
#
#
# Note:
#
#
# If there is no such window in S that covers all characters in T, return the
# empty string "".
# If there is such window, you are guaranteed that there will always be only
# one unique minimum window in S.
#
#
#

from collections import defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if s == "" or t == "":
            return ""

        dict_t = defaultdict(int)
        for c in t:
            dict_t[c] += 1
        remains = len(t)

        left = right = 0
        result = (0, len(s)+1)

        while right < len(s) or remains == 0:
            if remains > 0:
                dict_t[s[right]] -= 1
                if dict_t[s[right]] >= 0:
                    remains -= 1
                right += 1

            if remains == 0:  # valid window
                if result[1] - result[0] > right - left:
                    result = (left, right)
                dict_t[s[left]] += 1
                if dict_t[s[left]] > 0:
                    remains += 1
                left += 1

        if result[1] > len(s):
            return ""
        else:
            return s[result[0]:result[1]]


# def main():
#     solu = Solution()
#     print(solu.minWindow("ADOBECODEBANC", "ABC"))  # "BANC"
#     print(solu.minWindow("a", "aa"))  # ""
#     print(solu.minWindow("aa", "aa"))  # "aa"
#     print(solu.minWindow("a", ""))  # ""


# if __name__ == "__main__":
#     main()
