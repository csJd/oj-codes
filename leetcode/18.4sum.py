#
# @lc app=leetcode id=18 lang=python3
#
# [18] 4Sum
#
'''
Tags
array | hash-table | two-pointers

Companies
linkedin

Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
'''
from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        results = []

        def nSum(n, nums, target, record, results):
            if len(nums) < n or nums[0] * n > target or nums[-1] * n < target:
                return

            # two pointers for two-sum problem
            if n == 2:
                l, r = 0, len(nums) - 1
                while l < r:
                    if nums[l] + nums[r] == target:
                        results.append(record + [nums[l], nums[r]])
                        l += 1
                        r -= 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1
                    elif nums[l] + nums[r] < target:
                        l += 1
                    else:
                        r -= 1

            else:
                for i in range(len(nums) - n + 1):
                    if i > 0 and nums[i] == nums[i-1]:
                        continue
                    nSum(n-1, nums[i+1:], target-nums[i],
                         record + [nums[i]], results)
        nSum(4, nums, target, [], results)
        return results


def main():
    solu = Solution()
    print(solu.fourSum([1, 0, -1, 0, -2, 2], 0))
    print(solu.fourSum([-1, 0, -5, -2, -2, -4, 0, 1, -2], -9))


if __name__ == "__main__":
    main()
