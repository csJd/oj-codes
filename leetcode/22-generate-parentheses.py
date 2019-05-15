#
# @lc app=leetcode id=22 lang=python3
#
# [22] Generate Parentheses
#

from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = {''}   # do not use set(''), they are different
        for i in range(n):
            new_res = set()
            for x in res:
                new_res.add('('+x+')')
                for j in range(len(x)):
                    # '()' can be inserted anywhere
                    new_res.add(x[:j] + '()' + x[j:])
            res = new_res
        return list(res)


def main():
    solu = Solution()
    print(solu.generateParenthesis(4))


if __name__ == "__main__":
    main()
