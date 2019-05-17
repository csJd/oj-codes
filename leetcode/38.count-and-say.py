#
# @lc app=leetcode id=38 lang=python3
#
# [38] Count and Say
#
# https://leetcode.com/problems/count-and-say/description/
#
# algorithms
# Easy (40.36%)
# Likes:    742
# Dislikes: 5724
# Total Accepted:    279.8K
# Total Submissions: 693K
# Testcase Example:  '1'
#
# The count-and-say sequence is the sequence of integers with the first five
# terms as following:
#
#
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
#
#
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
#
# Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
# count-and-say sequence.
#
# Note: Each term of the sequence of integers will be represented as a
# string.
#
#
#
# Example 1:
#
#
# Input: 1
# Output: "1"
#
#
# Example 2:
#
#
# Input: 4
# Output: "1211"
#
#


class Solution:
    def countAndSay(self, n: int) -> str:
        s = '1'
        for i in range(n-1):
            length = len(s)
            new_s = ''
            start = 0
            for i in range(length+1):
                if i >= length or s[i] != s[start]:
                    new_s += str(i-start) + s[start]
                    start = i
            s = new_s
        return s


def main():
    solu = Solution()
    print(solu.countAndSay(5))


if __name__ == "__main__":
    main()
