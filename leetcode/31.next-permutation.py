#
# @lc app=leetcode id=31 lang=python3
#
# [31] Next Permutation
#
# https://leetcode.com/problems/next-permutation/description/
#
# algorithms
# Medium (30.41%)
# Likes:    1718
# Dislikes: 524
# Total Accepted:    234K
# Total Submissions: 769.4K
# Testcase Example:  '[1,2,3]'
#
# Implement next permutation, which rearranges numbers into the
# lexicographically next greater permutation of numbers.
#
# If such arrangement is not possible, it must rearrange it as the lowest
# possible order (ie, sorted in ascending order).
#
# The replacement must be in-place and use only constant extra memory.
#
# Here are some examples. Inputs are in the left-hand column and its
# corresponding outputs are in the right-hand column.
#
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
#
#

from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        pos = 0
        for i in range(length - 1, 0, -1):
            if nums[i] > nums[i-1]:
                pos = ind = i
                for j in range(i, length):
                    if nums[j] > nums[i-1]:
                        ind = j
                nums[ind], nums[i-1] = nums[i-1], nums[ind]
                break
        for i in range(pos, (pos + length)//2):
            nums[i], nums[pos + length - 1 - i] \
                = nums[pos + length - 1 - i], nums[i]


def main():
    solu = Solution()
    arr = [1, 1, 5]
    solu.nextPermutation(arr)
    print(arr)


if __name__ == "__main__":
    main()
