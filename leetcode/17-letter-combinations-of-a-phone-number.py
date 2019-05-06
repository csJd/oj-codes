#
# @lc app=leetcode id=17 lang=python3
#
# [17] Letter Combinations of a Phone Number
#
'''
Tags
backtracking | string

Companies
amazon | dropbox | facebook | google | uber

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
'''

from typing import List


class Solution:

    def letterCombinations(self, digits: str) -> List[str]:
        dic = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
               '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        sets = [dic[d] for d in digits]
        result = [''] if len(sets) > 0 else []
        for s in sets:
            result = [x + y for x in result for y in s]

        return result


def main():
    solu = Solution()
    print(solu.letterCombinations("23"))
    print(solu.letterCombinations(""))


if __name__ == "__main__":
    main()
    pass
