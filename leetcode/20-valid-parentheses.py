#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#

'''
Tags
stack | string

Companies
airbnb | amazon | bloomberg | facebook | google | microsoft | twitter | zenefits

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

 1. Open brackets must be closed by the same type of brackets.
 2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
'''


class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'(': ')', '[': ']', '{': '}'}
        stack = list()
        for c in s:
            if len(stack) == 0 or dic[stack[-1]] != c:
                if c in ')]}':
                    return False
                stack.append(c)
            else:
                stack.pop()
        return len(stack) == 0
