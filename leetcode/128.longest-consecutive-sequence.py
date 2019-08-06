#
# @lc app=leetcode id=128 lang=python3
#
# [128] Longest Consecutive Sequence
#
# https://leetcode.com/problems/longest-consecutive-sequence/description/
#
# algorithms
# Hard (41.38%)
# Likes:    2032
# Dislikes: 99
# Total Accepted:    220.6K
# Total Submissions: 521.3K
# Testcase Example:  '[100,4,200,1,3,2]'
#
# Given an unsorted array of integers, find the length of the longest
# consecutive elements sequence.
#
# Your algorithm should run in O(n) complexity.
#
# Example:
#
#
# Input: [100, 4, 200, 1, 3, 2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
# Therefore its length is 4.
#
#
#

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        rng = dict()
        result = 0

        for num in nums:
            if num in rng:
                continue

            left = right = num
            if num - 1 in rng:
                left = rng[num-1][0]
            if num + 1 in rng:
                right = rng[num+1][1]
            if num - 1 in rng:
                rng[left][1] = right
            if num + 1 in rng:
                rng[right][0] = left

            rng[num] = [left, right]

            result = max(result, right - left + 1)

        return result


# def main():
#     solu = Solution()
#     print(solu.longestConsecutive([100, 4, 200, 1, 3, 2]))
#     print(solu.longestConsecutive([4, 1, 3, 3, 5, 2, 100, 0]))
#     print(solu.longestConsecutive([]))
#     pass


# if __name__ == "__main__":
#     main()
