#
# @lc app=leetcode id=92 lang=python3
#
# [92] Reverse Linked List II
#
# https://leetcode.com/problems/reverse-linked-list-ii/description/
#
# algorithms
# Medium (34.61%)
# Likes:    1340
# Dislikes: 97
# Total Accepted:    205.1K
# Total Submissions: 577.2K
# Testcase Example:  '[1,2,3,4,5]\n2\n4'
#
# Reverse a linked list from position m to n. Do it in one-pass.
#
# Note: 1 ≤ m ≤ n ≤ length of list.
#
# Example:
#
#
# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL
#
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        pseudo_head = ListNode(0)
        pseudo_head.next = head

        cnt = 1
        left = pseudo_head
        while cnt < m:
            left = left.next
            cnt += 1

        tail = left.next
        while cnt < n:
            tmp = tail.next.next

            tail.next.next = left.next
            left.next = tail.next
            tail.next = tmp

            cnt += 1

        return pseudo_head.next
