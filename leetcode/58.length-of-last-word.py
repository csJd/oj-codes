#
# @lc app=leetcode id=58 lang=python3
#
# [58] Length of Last Word
#
# https://leetcode.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (32.23%)
# Likes:    365
# Dislikes: 1529
# Total Accepted:    266.1K
# Total Submissions: 824.9K
# Testcase Example:  '"Hello World"'
#
# Given a string s consists of upper/lower-case alphabets and empty space
# characters ' ', return the length of last word in the string.
#
# If the last word does not exist, return 0.
#
# Note: A word is defined as a character sequence consists of non-space
# characters only.
#
# Example:
#
#
# Input: "Hello World"
# Output: 5
#
#
#
#
#


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = len(s)
        start, end = -1, -2
        for i in range(length-1, -1, -1):
            if s[i] != ' ':
                if end >= 0:
                    start = i
                else:
                    end = start = i
            elif start >= 0:
                break
        return end - start + 1


def main():
    solu = Solution()
    print(solu.lengthOfLastWord(""))


if __name__ == "__main__":
    main()
