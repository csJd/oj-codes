#
# @lc app=leetcode id=179 lang=python3
#
# [179] Largest Number
#
# https://leetcode.com/problems/largest-number/description/
#
# algorithms
# Medium (26.29%)
# Likes:    1138
# Dislikes: 147
# Total Accepted:    138.4K
# Total Submissions: 525.7K
# Testcase Example:  '[10,2]'
#
# Given a list of non negative integers, arrange them such that they form the
# largest number.
#
# Example 1:
#
#
# Input: [10,2]
# Output: "210"
#
# Example 2:
#
#
# Input: [3,30,34,5,9]
# Output: "9534330"
#
#
# Note: The result may be very large, so you need to return a string instead of
# an integer.
#
#

from functools import cmp_to_key
from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:

        def mycmp(a, b):
            if a + b > b + a:
                return -1
            elif a + b < b + a:
                return 1
            return 0

        nums = [str(num) for num in nums]
        nums.sort(key=cmp_to_key(mycmp))
        if nums and nums[0] == nums[-1] == '0':
            return "0"
        return "".join(nums)


def main():
    solu = Solution()
    print(solu.largestNumber([10, 2]))
    print(solu.largestNumber([0, 0]))
    print(solu.largestNumber([3, 30, 34, 5, 9]))


if __name__ == "__main__":
    main()
