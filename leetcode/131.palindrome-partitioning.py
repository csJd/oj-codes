#
# @lc app=leetcode id=131 lang=python3
#
# [131] Palindrome Partitioning
#
# https://leetcode.com/problems/palindrome-partitioning/description/
#
# algorithms
# Medium (40.40%)
# Likes:    1024
# Dislikes: 40
# Total Accepted:    173.7K
# Total Submissions: 414.2K
# Testcase Example:  '"aab"'
#
# Given a string s, partition s such that every substring of the partition is a
# palindrome.
#
# Return all possible palindrome partitioning of s.
#
# Example:
#
#
# Input: "aab"
# Output:
# [
# ⁠ ["aa","b"],
# ⁠ ["a","a","b"]
# ]
#
#
#

from typing import List


class Solution:

    def partition(self, s: str) -> List[List[str]]:

        length = len(s)
        result = []
        memory = [[None] * length for i in range(length)]

        def is_palindrome(i, j):
            if j <= i:
                return 1
            if memory[i][j] is None:
                if s[i] != s[j]:
                    memory[i][j] = False
                else:
                    memory[i][j] = is_palindrome(i+1, j-1)
            return memory[i][j]

        def dfs(cur, pos):
            if pos >= length:
                if is_palindrome(length-len(cur[-1]), length-1):
                    result.append(cur)
                return

            # join to last part
            if cur:
                new_cur = cur.copy()
                new_cur[-1] += s[pos]
                dfs(new_cur, pos+1)

            # treat as a new part
            if (not cur) or is_palindrome(pos-len(cur[-1]), pos-1):
                dfs(cur+[s[pos]], pos+1)

        dfs([], 0)
        return result


def main():
    solu = Solution()
    print(solu.partition("aab"))
    print(solu.partition("efe"))


if __name__ == "__main__":
    main()
