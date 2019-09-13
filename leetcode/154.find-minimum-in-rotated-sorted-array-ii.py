#
# @lc app=leetcode id=154 lang=python3
#
# [154] Find Minimum in Rotated Sorted Array II
#
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
#
# algorithms
# Hard (39.19%)
# Likes:    502
# Dislikes: 152
# Total Accepted:    137.9K
# Total Submissions: 347.9K
# Testcase Example:  '[1,3,5]'
#
# Suppose an array sorted in ascending order is rotated at some pivot unknown
# to you beforehand.
#
# (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
#
# Find the minimum element.
#
# The array may contain duplicates.
#
# Example 1:
#
#
# Input: [1,3,5]
# Output: 1
#
# Example 2:
#
#
# Input: [2,2,2,0,1]
# Output: 0
#
# Note:
#
#
# This is a follow up problem to Find Minimum in Rotated Sorted Array.
# Would allow duplicates affect the run-time complexity? How and why?
#
#
#


from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        length = len(nums)
        le, ri = 0, length - 1

        while le <= ri:
            mid = (le + ri) >> 1

            # miv_val must in [mid+1:ri]
            if nums[mid] > nums[ri]:
                le = mid + 1
            # min_val must in [le:mid]
            elif nums[mid] < nums[ri]:
                ri = mid
            # nums[mid] == nums[ri], can not determine, just ri-=1
            else:
                # find the pivot ri
                if nums[ri] < nums[ri-1]:
                    return nums[ri]
                ri -= 1

        # le is the pivot
        return nums[le]

    def findMinMy(self, nums: List[int]) -> int:
        length = len(nums)
        le, ri = 0, length - 1

        min_val = nums[0]
        while le <= ri:
            mid = (le + ri) >> 1
            # the only case that [le:mid] can be not inorder
            # when nums[le] <= nums[mid]
            if nums[le] == nums[mid] == nums[ri]:
                min_val = min(min_val, nums[le])
                ri -= 1
            # nums[le:mid] is inorder
            elif nums[le] <= nums[mid]:
                min_val = min(min_val, nums[le])
                le = mid + 1
            # nums[le] > nums[mid], mid in the right part
            # nums[mid:ri] is inorder
            else:
                min_val = min(min_val, nums[mid])
                ri = mid - 1

        return min_val


def main():
    solu = Solution()
    print(solu.findMin([2, 2, 2, 0, 1]))
    print(solu.findMin([4, 5, 1, 2, 3]))
    print(solu.findMin([1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1]))
    print(solu.findMin([2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2]))


if __name__ == "__main__":
    main()
