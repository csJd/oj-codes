#
# @lc app=leetcode id=43 lang=python3
#
# [43] Multiply Strings
#
# https://leetcode.com/problems/multiply-strings/description/
#
# algorithms
# Medium (30.40%)
# Likes:    963
# Dislikes: 442
# Total Accepted:    198.8K
# Total Submissions: 650.1K
# Testcase Example:  '"2"\n"3"'
#
# Given two non-negative integers num1 and num2 represented as strings, return
# the product of num1 and num2, also represented as a string.
#
# Example 1:
#
#
# Input: num1 = "2", num2 = "3"
# Output: "6"
#
# Example 2:
#
#
# Input: num1 = "123", num2 = "456"
# Output: "56088"
#
#
# Note:
#
#
# The length of both num1 and num2 is < 110.
# Both num1 and num2 contain only digits 0-9.
# Both num1 and num2 do not contain any leading zero, except the number 0
# itself.
# You must not use any built-in BigInteger library or convert the inputs to
# integer directly.
#
#
#


class Solution:
    def add(self, num1: str, num2: str) -> str:
        len1, len2 = len(num1), len(num2)
        pos = -1
        result = list()
        carry = 0
        while pos + len2 >= 0 or pos + len1 >= 0 or carry > 0:
            d1 = d2 = 0
            if pos + len1 >= 0:
                d1 = int(num1[pos])
            if pos + len2 >= 0:
                d2 = int(num2[pos])
            digit = (d1 + d2 + carry) % 10
            carry = (d1 + d2 + carry) // 10
            # list.insert() is O(n), list.append() is O(1)
            result.append(str(digit))
            pos -= 1
        result.reverse()
        return ''.join(result)

    def multiply(self, num1: str, num2: str) -> str:
        if num1 == '0' or num2 == '0':
            return '0'
        len1, len2 = len(num1), len(num2)
        result = '0'
        append = ''
        for i in range(len2 - 1, -1, -1):
            if len1 == 1:
                result = self.add(result, str(
                    int(num2[i]) * int(num1)) + append)
            else:
                result = self.add(
                    result, self.multiply(num2[i], num1) + append)
            append += '0'
        return result


def main():
    solu = Solution()
    print(solu.add('0', '11'))
    print(solu.multiply('123', '456'))


if __name__ == "__main__":
    main()
