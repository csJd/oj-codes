#
# @lc app=leetcode id=23 lang=python3
#
# [23] Merge k Sorted Lists
#
# https://leetcode.com/problems/merge-k-sorted-lists/description/
#
# algorithms
# Hard (34.27%)
# Likes:    2406
# Dislikes: 153
# Total Accepted:    383.5K
# Total Submissions: 1.1M
# Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
#
# Merge k sorted linked lists and return it as one sorted list. Analyze and
# describe its complexity.
#
# Example:
#
#
# Input:
# [
# 1->4->5,
# 1->3->4,
# 2->6
# ]
# Output: 1->1->2->3->4->4->5->6
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        root = ListNode(0)
        p = root
        finished = (len(lists) == 0)
        while not finished:
            min_v = float('inf')
            s_ind = 0
            for ind, lis in enumerate(lists):
                if lis and lis.val < min_v:
                    s_ind = ind
                    min_v = lis.val
            if lists[s_ind] is None:
                finished = True
            else:
                p.next, lists[s_ind] = lists[s_ind], lists[s_ind].next
                p = p.next
        return root.next
