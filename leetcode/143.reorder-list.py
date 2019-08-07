#
# @lc app=leetcode id=143 lang=python3
#
# [143] Reorder List
#
# https://leetcode.com/problems/reorder-list/description/
#
# algorithms
# Medium (30.44%)
# Likes:    1002
# Dislikes: 74
# Total Accepted:    164.5K
# Total Submissions: 519K
# Testcase Example:  '[1,2,3,4]'
#
# Given a singly linked list L: L0→L1→…→Ln-1→Ln,
# reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
#
# You may not modify the values in the list's nodes, only nodes itself may be
# changed.
#
# Example 1:
#
#
# Given 1->2->3->4, reorder it to 1->4->2->3.
#
# Example 2:
#
#
# Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:

    def reverse(self, head: ListNode) -> ListNode:
        """
        Rerverse a linked list in place
        """
        pseudo_head = ListNode(0)
        pseudo_head.next = head
        while head.next:
            node = head.next
            head.next = node.next
            node.next = pseudo_head.next
            pseudo_head.next = node
        return pseudo_head.next

    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        length = 0
        p = head
        while p:
            length += 1
            p = p.next

        if length <= 1:
            return

        p = right_head = head
        pos = 0
        while p:
            pos += 1
            if pos == (length+1) // 2:
                right_head = p.next
                p.next = None
            p = p.next

        right_head = self.reverse(right_head)

        # join reverised right part to linked list
        p = head
        p_right = right_head
        while p_right:
            node = p_right
            p_right = node.next
            node.next = p.next
            p.next = node
            p = node.next
