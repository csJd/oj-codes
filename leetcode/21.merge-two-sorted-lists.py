#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        root = ListNode(0)
        p = root
        while l1 or l2:
            if l1 and (l2 is None or l1.val < l2.val):
                p.next, l1 = l1, l1.next
            else:
                p.next, l2 = l2, l2.next
            p = p.next
        return root.next
