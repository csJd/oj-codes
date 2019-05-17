#
# @lc app=leetcode id=34 lang=python3
#
# [34] Find First and Last Position of Element in Sorted Array
#
# https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#
# algorithms
# Medium (33.47%)
# Likes:    1525
# Dislikes: 85
# Total Accepted:    296.1K
# Total Submissions: 884.7K
# Testcase Example:  '[5,7,7,8,8,10]\n8'
#
# Given an array of integers nums sorted in ascending order, find the starting
# and ending position of a given target value.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# If the target is not found in the array, return [-1, -1].
#
# Example 1:
#
#
# Input: nums = [5,7,7,8,8,10], target = 8
# Output: [3,4]
#
# Example 2:
#
#
# Input: nums = [5,7,7,8,8,10], target = 6
# Output: [-1,-1]
#
#
from typing import List


class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        length = len(nums)
        le, ri = 0, length - 1
        lind = rind = -1
        while(le <= ri):
            mid = (le + ri) >> 1
            if nums[mid] < target:
                le = mid + 1
            else:
                ri = mid - 1
        if ri + 1 < length and nums[ri+1] == target:
            lind = ri + 1

        if 0 <= lind < length-1 and nums[lind + 1] != nums[lind]:
            rind = lind
        else:
            ri = length - 1
            while(le <= ri):
                mid = (le + ri) >> 1
                if nums[mid] <= target:
                    le = mid + 1
                else:
                    ri = mid - 1
            if le - 1 >= 0 and nums[le - 1] == target:
                rind = le - 1

        return [lind, rind]


def main():
    solu = Solution()
    print(solu.searchRange([], 1))
    print(solu.searchRange([1], 1))
    print(solu.searchRange([5, 7, 7, 8, 8, 10], 6))


if __name__ == "__main__":
    main()
