"""
1157. Online Majority Element In Subarray
https://leetcode.com/problems/online-majority-element-in-subarray/

Implementing the class MajorityChecker, which has the following API:

MajorityChecker(int[] arr) constructs an instance of MajorityChecker with the given array arr;
int query(int left, int right, int threshold) has arguments such that:
0 <= left <= right < arr.length representing a subarray of arr;
2 * threshold > right - left + 1, ie. the threshold is always a strict majority of the length of the subarray
Each query(...) returns the element in arr[left], arr[left+1], ..., arr[right] that occurs at least threshold times, or -1 if no such element exists.



Example:

MajorityChecker majorityChecker = new MajorityChecker([1,1,2,2,1,1]);
majorityChecker.query(0,5,4); // returns 1
majorityChecker.query(0,3,3); // returns -1
majorityChecker.query(2,3,2); // returns 2


Constraints:

1 <= arr.length <= 20000
1 <= arr[i] <= 20000
For each query, 0 <= left <= right < len(arr)
For each query, 2 * threshold > right - left + 1
The number of queries is at most 10000
"""

import collections
import bisect
import random
from typing import List


class MajorityChecker:
    def __init__(self, arr: List[int]):
        num_indices = collections.defaultdict(list)
        for i, num in enumerate(arr):
            num_indices[num].append(i)
        self.arr = arr
        self.num_indices = num_indices

    def query(self, left: int, right: int, threshold: int) -> int:
        for t in range(19):
            rnd = self.arr[random.randint(left, right)]
            indices = self.num_indices[rnd]
            le = bisect.bisect_left(indices, left)
            ri = bisect.bisect_right(indices, right)
            if ri - le >= threshold:
                return rnd
        return -1

    # def __init__(self, arr: List[int]):
        # self.arr = arr.copy()

    def queryOn(self, left: int, right: int, threshold: int) -> int:
        # Your MajorityChecker object will be instantiated and called as such:
        # obj = MajorityChecker(arr)
        # param_1 = obj.query(left,right,threshold)

        marjority = cnt = 0
        # find the marjority in O(n) time
        for i in range(left, right+1):
            if self.arr[i] == marjority:
                cnt += 1
            elif cnt > 0:
                cnt -= 1
            else:
                marjority = self.arr[i]
                cnt = 1

        cnt = 0
        for i in range(left, right+1):
            if self.arr[i] == marjority:
                cnt += 1

        if cnt < threshold:
            marjority = -1

        return marjority
