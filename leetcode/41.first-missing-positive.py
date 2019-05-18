#
# @lc app=leetcode id=41 lang=python3
#
# [41] First Missing Positive
#
# https://leetcode.com/problems/first-missing-positive/description/
#
# algorithms
# Hard (28.79%)
# Likes:    1611
# Dislikes: 557
# Total Accepted:    210K
# Total Submissions: 729K
# Testcase Example:  '[1,2,0]'
#
# Given an unsorted integer array, find the smallest missing positive integer.
#
# Example 1:
#
#
# Input: [1,2,0]
# Output: 3
#
#
# Example 2:
#
#
# Input: [3,4,-1,1]
# Output: 2
#
#
# Example 3:
#
#
# Input: [7,8,9,11,12]
# Output: 1
#
#
# Note:
#
# Your algorithm should run in O(n) time and uses constant extra space.
#
#


from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.insert(0, 0)
        length = len(nums)
        for i, num in enumerate(nums):
            while 0 < num < length and i != num and nums[i] != nums[num]:
                nums[num], nums[i] = num, nums[num]
                num = nums[i]
                # move num to it's
        for i, num in enumerate(nums):
            if num != i:
                return i
        return length


def main():
    solu = Solution()
    print(solu.firstMissingPositive([7, 8, 9, 11, 12]))
    print(solu.firstMissingPositive([3, 4, 1, 1]))
    print(solu.firstMissingPositive([1, 1, 1, 4]))


if __name__ == "__main__":
    main()
