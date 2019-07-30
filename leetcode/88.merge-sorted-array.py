#
# @lc app=leetcode id=88 lang=python3
#
# [88] Merge Sorted Array
#
# https://leetcode.com/problems/merge-sorted-array/description/
#
# algorithms
# Easy (35.60%)
# Likes:    1201
# Dislikes: 2922
# Total Accepted:    390.1K
# Total Submissions: 1.1M
# Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
#
# Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
# one sorted array.
#
# Note:
#
#
# The number of elements initialized in nums1 and nums2 are m and n
# respectively.
# You may assume that nums1 has enough space (size that is greater or equal to
# m + n) to hold additional elements from nums2.
#
#
# Example:
#
#
# Input:
# nums1 = [1,2,3,0,0,0], m = 3
# nums2 = [2,5,6],       n = 3
#
# Output: [1,2,2,3,5,6]
#
#
#


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        length = m + n
        for i in range(length-1, length-m-1, -1):
            nums1[i] = nums1[i - n]

        i = length - m
        j = 0
        pos = 0

        while(j < n):
            if i >= length or nums2[j] <= nums1[i]:
                nums1[pos] = nums2[j]
                j += 1
            else:
                nums1[pos] = nums1[i]
                i += 1
            pos += 1
