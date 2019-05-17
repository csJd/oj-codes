#
# @lc app=leetcode id=24 lang=python3
#
# [24] Swap Nodes in Pairs
#
# https://leetcode.com/problems/swap-nodes-in-pairs/description/
#
# algorithms
# Medium (44.47%)
# Likes:    1092
# Dislikes: 99
# Total Accepted:    310.3K
# Total Submissions: 697.5K
# Testcase Example:  '[1,2,3,4]'
#
# Given a linked list, swap every two adjacent nodes and return its head.
#
# You may not modify the values in the list's nodes, only nodes itself may be
# changed.
#
#
#
# Example:
#
#
# Given 1->2->3->4, you should return the list as 2->1->4->3.
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        pseudo_head = ListNode(0)
        pseudo_head.next = head
        p = pseudo_head
        while p.next:
            first = p.next
            second = first.next
            if second:
                tmp = second.next
                second.next = first
                first.next = tmp
                p.next = second
            p = first
        return pseudo_head.next
