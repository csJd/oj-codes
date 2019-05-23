#
# @lc app=leetcode id=55 lang=python3
#
# [55] Jump Game
#
# https://leetcode.com/problems/jump-game/description/
#
# algorithms
# Medium (31.71%)
# Likes:    1876
# Dislikes: 192
# Total Accepted:    261.3K
# Total Submissions: 820.3K
# Testcase Example:  '[2,3,1,1,4]'
#
# Given an array of non-negative integers, you are initially positioned at the
# first index of the array.
#
# Each element in the array represents your maximum jump length at that
# position.
#
# Determine if you are able to reach the last index.
#
# Example 1:
#
#
# Input: [2,3,1,1,4]
# Output: true
# Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
#
#
# Example 2:
#
#
# Input: [3,2,1,0,4]
# Output: false
# Explanation: You will always arrive at index 3 no matter what. Its
# maximum
# jump length is 0, which makes it impossible to reach the last index.
#
#
#

from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        length = len(nums)
        pos = 0
        while pos < length - 1:
            if nums[pos] <= 0:
                return False
            tmp = pos
            for i in range(tmp+1, pos+nums[tmp] + 1):
                if (i >= length - 1) or (i + nums[i] >= length - 1):
                    return True
                if i + nums[i] >= pos + nums[pos]:
                    pos = i
        return True


def main():
    solu = Solution()
    print(solu.canJump([3, 2, 1, 0, 4]))
    print(solu.canJump([2, 3, 1, 1, 4]))
    print(solu.canJump([2, 1]))


if __name__ == "__main__":
    main()
