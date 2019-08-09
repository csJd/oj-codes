#
# @lc app=leetcode id=150 lang=python3
#
# [150] Evaluate Reverse Polish Notation
#
# https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
#
# algorithms
# Medium (31.87%)
# Likes:    574
# Dislikes: 368
# Total Accepted:    172.4K
# Total Submissions: 523.8K
# Testcase Example:  '["2","1","+","3","*"]'
#
# Evaluate the value of an arithmetic expression in Reverse Polish Notation.
#
# Valid operators are +, -, *, /. Each operand may be an integer or another
# expression.
#
# Note:
#
#
# Division between two integers should truncate toward zero.
# The given RPN expression is always valid. That means the expression would
# always evaluate to a result and there won't be any divide by zero
# operation.
#
#
# Example 1:
#
#
# Input: ["2", "1", "+", "3", "*"]
# Output: 9
# Explanation: ((2 + 1) * 3) = 9
#
#
# Example 2:
#
#
# Input: ["4", "13", "5", "/", "+"]
# Output: 6
# Explanation: (4 + (13 / 5)) = 6
#
#
# Example 3:
#
#
# Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
# Output: 22
# Explanation:
# ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
# = ((10 * (6 / (12 * -11))) + 17) + 5
# = ((10 * (6 / -132)) + 17) + 5
# = ((10 * 0) + 17) + 5
# = (0 + 17) + 5
# = 17 + 5
# = 22
#
#
#

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = list()
        for token in tokens:
            if token in "+-*/":
                b = stack.pop()
                a = stack.pop()
                if token == '+':
                    stack.append(a + b)
                elif token == '-':
                    stack.append(a - b)
                elif token == '*':
                    stack.append(a * b)
                elif token == '/':
                    res = a // b
                    if res < 0 and a % b != 0:
                        res += 1
                    stack.append(res)
            else:
                stack.append(int(token))
        return stack.pop()


def main():
    solu = Solution()
    print(solu.evalRPN(["10", "6", "9", "3", "+",
                        "-11", "*", "/", "*", "17", "+", "5", "+"]))


if __name__ == "__main__":
    main()
