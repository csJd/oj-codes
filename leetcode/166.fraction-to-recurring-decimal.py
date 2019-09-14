#
# @lc app=leetcode id=166 lang=python3
#
# [166] Fraction to Recurring Decimal
#
# https://leetcode.com/problems/fraction-to-recurring-decimal/description/
#
# algorithms
# Medium (19.77%)
# Likes:    512
# Dislikes: 1127
# Total Accepted:    93K
# Total Submissions: 469.9K
# Testcase Example:  '1\n2'
#
# Given two integers representing the numerator and denominator of a fraction,
# return the fraction in string format.
#
# If the fractional part is repeating, enclose the repeating part in
# parentheses.
#
# Example 1:
#
#
# Input: numerator = 1, denominator = 2
# Output: "0.5"
#
#
# Example 2:
#
#
# Input: numerator = 2, denominator = 1
# Output: "2"
#
# Example 3:
#
#
# Input: numerator = 2, denominator = 3
# Output: "0.(6)"
#
#
#


class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        history = dict()
        if numerator % denominator == 0:
            return str(numerator // denominator)

        negative = False
        if numerator * denominator < 0:
            negative = True
            if numerator < 0:
                numerator = -numerator
            else:
                denominator = -denominator

        result = [str(numerator // denominator)] + ['.']
        numerator %= denominator
        pos = len(result)

        while numerator and numerator not in history:
            history[numerator] = pos
            pos += 1
            numerator = numerator * 10
            cur_res = numerator // denominator
            result.append(str(cur_res))
            numerator %= denominator

        if numerator:
            result.insert(history[numerator], '(')
            result.append(')')

        if negative:
            result.insert(0, '-')

        return ''.join(result)


def main():
    solu = Solution()
    print(solu.fractionToDecimal(2, 3))
    print(solu.fractionToDecimal(1, 2))
    print(solu.fractionToDecimal(2, 1))
    print(solu.fractionToDecimal(-50, 8))


if __name__ == "__main__":
    main()
