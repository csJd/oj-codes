#
# @lc app=leetcode id=81 lang=python3
#
# [81] Search in Rotated Sorted Array II
#
# https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
#
# algorithms
# Medium (32.57%)
# Likes:    718
# Dislikes: 336
# Total Accepted:    179.8K
# Total Submissions: 549.7K
# Testcase Example:  '[2,5,6,0,0,1,2]\n0'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
#
# (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
#
# You are given a target value to search. If found in the array return true,
# otherwise return false.
#
# Example 1:
#
#
# Input: nums = [2,5,6,0,0,1,2], target = 0
# Output: true
#
#
# Example 2:
#
#
# Input: nums = [2,5,6,0,0,1,2], target = 3
# Output: false
#
# Follow up:
#
#
# This is a follow up problem to Search in Rotated Sorted Array, where nums may
# contain duplicates.
# Would this affect the run-time complexity? How and why?
#
#
#

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        n_nums = len(nums)

        le = 0
        ri = n_nums - 1
        while le <= ri:
            mid = (le + ri) >> 1
            if nums[mid] == target:
                return True

            # only in this case, (nums[le] <= nums[mid]) ==!> nums[le:mid] is in order
            if nums[le] == nums[ri] == nums[mid]:
                ri -= 1

            elif nums[le] <= nums[mid]:  # nums[le:mid] is in order
                if nums[le] <= target < nums[mid]:
                    ri = mid - 1
                else:
                    le = mid + 1
            else:  # nums[le] > nums[mid], mid is in right part, nums[mid:ri] is in order
                if nums[mid] < target <= nums[ri]:
                    le = mid + 1
                else:
                    ri = mid - 1

        return False


# def main():
#     solu = Solution()
#     print(solu.search([2, 5, 6, 0, 0, 1, 2], 0))
#     print(solu.search([2, 5, 6, 0, 0, 1, 2], 3))
#     print(solu.search([2, 0, 2, 2], 3))
#     print(solu.search([2, 2, 2], 3))
#     print(solu.search([2, 2, 2], 2))
#     print(solu.search([1, 1, 1, 3, 1], 3))
#     print(solu.search([2, 2, 1, 2, 2, 2, 2, 2, 2], 1))
#     print(solu.search([2, 2, 2, 2, 2, 2, 2, 1, 2], 1))


# if __name__ == "__main__":
#     main()
