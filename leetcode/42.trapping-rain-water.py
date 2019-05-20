#
# @lc app=leetcode id=42 lang=python3
#
# [42] Trapping Rain Water
#
# https://leetcode.com/problems/trapping-rain-water/description/
#
# algorithms
# Hard (42.74%)
# Likes:    3491
# Dislikes: 63
# Total Accepted:    289K
# Total Submissions: 671.3K
# Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
#
# Given n non-negative integers representing an elevation map where the width
# of each bar is 1, compute how much water it is able to trap after raining.
#
#
# The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In
# this case, 6 units of rain water (blue section) are being trapped. Thanks
# Marcos for contributing this image!
#
# Example:
#
#
# Input: [0,1,0,2,1,0,1,3,2,1,2,1]
# Output: 6
#
#
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        length = len(height)
        # forward
        last = 0
        accum = 0
        result = 0
        for i in range(length):
            if height[i] >= height[last]:
                result += height[last] * (i-last) - accum
                accum = 0
                last = i
            accum += height[i]

        # backward
        highest = last
        last = length - 1
        accum = 0
        for i in range(length-1, highest-1, -1):
            if height[i] >= height[last]:
                result += height[last] * (last-i) - accum
                accum = 0
                last = i
            accum += height[i]
        return result


def main():
    solu = Solution()
    print(solu.trap([0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]))
    print(solu.trap([0]))
    print(solu.trap([1, 2, 3, 4, 5]))


if __name__ == "__main__":
    main()
