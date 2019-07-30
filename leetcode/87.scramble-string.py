#
# @lc app=leetcode id=87 lang=python3
#
# [87] Scramble String
#
# https://leetcode.com/problems/scramble-string/description/
#
# algorithms
# Hard (31.52%)
# Likes:    311
# Dislikes: 508
# Total Accepted:    93.2K
# Total Submissions: 292.1K
# Testcase Example:  '"great"\n"rgeat"'
#
# Given a string s1, we may represent it as a binary tree by partitioning it to
# two non-empty substrings recursively.
#
# Below is one possible representation of s1 = "great":
#
#
# ⁠   great
# ⁠  /    \
# ⁠ gr    eat
# ⁠/ \    /  \
# g   r  e   at
# ⁠          / \
# ⁠         a   t
#
#
# To scramble the string, we may choose any non-leaf node and swap its two
# children.
#
# For example, if we choose the node "gr" and swap its two children, it
# produces a scrambled string "rgeat".
#
#
# ⁠   rgeat
# ⁠  /    \
# ⁠ rg    eat
# ⁠/ \    /  \
# r   g  e   at
# ⁠          / \
# ⁠         a   t
#
#
# We say that "rgeat" is a scrambled string of "great".
#
# Similarly, if we continue to swap the children of nodes "eat" and "at", it
# produces a scrambled string "rgtae".
#
#
# ⁠   rgtae
# ⁠  /    \
# ⁠ rg    tae
# ⁠/ \    /  \
# r   g  ta  e
# ⁠      / \
# ⁠     t   a
#
#
# We say that "rgtae" is a scrambled string of "great".
#
# Given two strings s1 and s2 of the same length, determine if s2 is a
# scrambled string of s1.
#
# Example 1:
#
#
# Input: s1 = "great", s2 = "rgeat"
# Output: true
#
#
# Example 2:
#
#
# Input: s1 = "abcde", s2 = "caebd"
# Output: false
#
#


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        mem_dict = dict()

        # whether a is scramble of b
        def dfs(a, b):
            if len(a) != len(b):
                return False
            if a == b:
                return True
            if (a, b) in mem_dict:
                return mem_dict[(a, b)]

            length = len(a)
            for i in range(1, length):
                if (dfs(a[:i], b[:i]) and dfs(a[i:], b[i:])) \
                        or (dfs(a[:i], b[-i:]) and dfs(a[i:], b[:-i])):
                    mem_dict[(a, b)] = True
                    return True

            mem_dict[(a, b)] = False
            return False

        return dfs(s1, s2)


# def main():
#     solu = Solution()
#     print(solu.isScramble("great", "rgeat"))


# if __name__ == "__main__":
#     main()
