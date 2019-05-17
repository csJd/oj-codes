#
# @lc app=leetcode id=25 lang=python3
#
# [25] Reverse Nodes in k-Group
#
# https://leetcode.com/problems/reverse-nodes-in-k-group/description/
#
# algorithms
# Hard (36.28%)
# Likes:    1136
# Dislikes: 242
# Total Accepted:    181.9K
# Total Submissions: 501.1K
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# Given a linked list, reverse the nodes of a linked list k at a time and
# return its modified list.
#
# k is a positive integer and is less than or equal to the length of the linked
# list. If the number of nodes is not a multiple of k then left-out nodes in
# the end should remain as it is.
#
#
#
#
# Example:
#
# Given this linked list: 1->2->3->4->5
#
# For k = 2, you should return: 2->1->4->3->5
#
# For k = 3, you should return: 3->2->1->4->5
#
# Note:
#
#
# Only constant extra memory is allowed.
# You may not alter the values in the list's nodes, only nodes itself may be
# changed.
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        pseudo_head = ListNode(0)
        pseudo_head.next = head
        p = pseudo_head
        remains = 0
        while head:
            remains += 1
            head = head.next

        while remains >= k > 1:
            remains -= k
            first = p.next
            for i in range(k-1):
                last = first.next
                tmp = last.next
                last.next = p.next
                p.next = last
                first.next = tmp
            p = first
        return pseudo_head.next
