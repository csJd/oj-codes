#
# @lc app=leetcode id=57 lang=python3
#
# [57] Insert Interval
#
# https://leetcode.com/problems/insert-interval/description/
#
# algorithms
# Hard (31.06%)
# Likes:    799
# Dislikes: 98
# Total Accepted:    175.9K
# Total Submissions: 564K
# Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
#
# Given a set of non-overlapping intervals, insert a new interval into the
# intervals (merge if necessary).
#
# You may assume that the intervals were initially sorted according to their
# start times.
#
# Example 1:
#
#
# Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
# Output: [[1,5],[6,9]]
#
#
# Example 2:
#
#
# Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
# Output: [[1,2],[3,10],[12,16]]
# Explanation: Because the new interval [4,8] overlaps with
# [3,5],[6,7],[8,10].
#
# NOTE: input types have been changed on April 15, 2019. Please reset to
# default code definition to get new method signature.
#
#

from typing import List


class Solution:

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        length = len(intervals)
        le, ri = 0, length-1
        while le <= ri:
            mid = (le + ri) >> 1
            if intervals[mid][0] <= newInterval[0]:
                le = mid + 1
            else:
                ri = mid - 1
        pos = ri + 1   # first position where interval[pos][0] > newInterval[0]
        intervals = intervals[:pos] + [newInterval] + intervals[pos:]

        # merger intervals
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
    print(solu.insert([[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], [4, 8]))


if __name__ == "__main__":
    main()
