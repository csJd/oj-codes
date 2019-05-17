#
# @lc app=leetcode id=19 lang=python3
#
# [19] Remove Nth Node From End of List
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        length = 0
        p = head
        while p is not None:
            length += 1
            p = p.next
        n = length - n + 1

        p = head
        last = None
        cnt = 1
        while cnt < n:
            cnt += 1
            last = p
            p = p.next

        if last:
            last.next = p.next
        else:
            head = head.next

        return head
