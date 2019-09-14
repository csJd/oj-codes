#
# @lc app=leetcode id=169 lang=python3
#
# [169] Majority Element
#
# https://leetcode.com/problems/majority-element/description/
#
# algorithms
# Easy (53.65%)
# Likes:    1883
# Dislikes: 161
# Total Accepted:    419.8K
# Total Submissions: 781.4K
# Testcase Example:  '[3,2,3]'
#
# Given an array of size n, find the majority element. The majority element is
# the element that appears more than ⌊ n/2 ⌋ times.
#
# You may assume that the array is non-empty and the majority element always
# exist in the array.
#
# Example 1:
#
#
# Input: [3,2,3]
# Output: 3
#
# Example 2:
#
#
# Input: [2,2,1,1,1,2,2]
# Output: 2
#
#
#

from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        majority = nums[0]
        cnt = 0
        for num in nums:
            if num == majority:
                cnt += 1
            elif cnt > 0:
                cnt -= 1
            else:
                majority = num
                cnt = 1
        return majority


def main():
    solu = Solution()
    print(solu.majorityElement([1, 2, 1, 3, 1, 4, 1]))
    print(solu.majorityElement([3]))


if __name__ == "__main__":
    main()
