#
# @lc app=leetcode id=56 lang=python3
#
# [56] Merge Intervals
#
# https://leetcode.com/problems/merge-intervals/description/
#
# algorithms
# Medium (35.39%)
# Likes:    2024
# Dislikes: 156
# Total Accepted:    344.2K
# Total Submissions: 967.8K
# Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
#
# Given a collection of intervals, merge all overlapping intervals.
#
# Example 1:
#
#
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
# [1,6].
#
#
# Example 2:
#
#
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
#
#

from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        length = len(intervals)
        if length == 0:
            return []
        result = []
        start, end = intervals[0]
        for interval in intervals:
            if interval[0] > end:
                result.append([start, end])
                start, end = interval
            elif interval[1] > end:
                end = interval[1]
        result.append([start, end])
        return result


def main():
    solu = Solution()
    print(solu.merge([[1, 3], [2, 6], [8, 10], [15, 18]]))
    print(solu.merge([[1, 1]]))


if __name__ == "__main__":
    main()
