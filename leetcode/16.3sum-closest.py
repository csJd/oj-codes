#
# @lc app=leetcode id=16 lang=python3
#
# [16] 3Sum Closest
#

'''
Tags
array | two-pointers

Companies
bloomberg

Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''
from typing import List
from bisect import bisect_left


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        new_nums = nums[:3]
        for i in range(3, len(nums)):
            if nums[i] != nums[i-3]:
                new_nums.append(nums[i])
        nums = new_nums
        length = len(nums)

        dist, ans = float('inf'), 0
        for i in range(length-2):
            for j in range(i+1, length-1):
                r = target - nums[i] - nums[j]
                r_ind = min(bisect_left(nums, r, lo=j+1), length-1)
                if r_ind-1 != j and abs(r-nums[r_ind-1] < dist):
                    k = r_ind-1
                    dist = abs(r-nums[r_ind-1])
                    ans = nums[i] + nums[j] + nums[k]
                if abs(r-nums[r_ind]) < dist:
                    k = r_ind
                    dist = abs(r-nums[r_ind])
                    ans = nums[i] + nums[j] + nums[k]
        return ans


def main():
    solu = Solution()
    print(solu.threeSumClosest([1, 1, 1, 0], -100))


if __name__ == "__main__":
    main()
