#
# @lc app=leetcode id=45 lang=python3
#
# [45] Jump Game II
#
# https://leetcode.com/problems/jump-game-ii/description/
#
# algorithms
# Hard (27.85%)
# Likes:    1134
# Dislikes: 56
# Total Accepted:    167.9K
# Total Submissions: 599.5K
# Testcase Example:  '[2,3,1,1,4]'
#
# Given an array of non-negative integers, you are initially positioned at the
# first index of the array.
#
# Each element in the array represents your maximum jump length at that
# position.
#
# Your goal is to reach the last index in the minimum number of jumps.
#
# Example:
#
#
# Input: [2,3,1,1,4]
# Output: 2
# Explanation: The minimum number of jumps to reach the last index is 2.
# ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
#
# Note:
#
# You can assume that you can always reach the last index.
#
#

from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        length = len(nums)
        choice = 0
        pos = 0
        count = 0
        while pos < length-1 and pos + nums[pos] < length - 1:
            # the position which can reach farest in next step is the best choice
            for i in range(pos, pos + nums[pos] + 1):
                if i < length and i + nums[i] >= choice + nums[choice]:
                    choice = i
            count += 1
            pos = choice
        if pos != length - 1:
            count += 1
        return count


def main():
    solu = Solution()
    print(solu.jump([2, 3, 1, 1, 4]))
    print(solu.jump([2, 3, 1]))
    print(solu.jump([0]))


if __name__ == "__main__":
    main()
