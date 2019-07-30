#
# @lc app=leetcode id=86 lang=python3
#
# [86] Partition List
#
# https://leetcode.com/problems/partition-list/description/
#
# algorithms
# Medium (37.10%)
# Likes:    736
# Dislikes: 196
# Total Accepted:    171.2K
# Total Submissions: 452.2K
# Testcase Example:  '[1,4,3,2,5,2]\n3'
#
# Given a linked list and a value x, partition it such that all nodes less than
# x come before nodes greater than or equal to x.
#
# You should preserve the original relative order of the nodes in each of the
# two partitions.
#
# Example:
#
#
# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5
#
#
#
# Definition for singly-linked list.


# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        lp = left_head = ListNode(0)
        rp = right_head = ListNode(0)
        cur = head
        while cur:
            if cur.val < x:
                lp.next = cur
                lp = cur
            else:
                rp.next = cur
                rp = cur
            cur = cur.next
        rp.next = None
        lp.next = right_head.next
        return left_head.next
