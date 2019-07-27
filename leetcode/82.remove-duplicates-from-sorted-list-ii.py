#
# @lc app=leetcode id=82 lang=python3
#
# [82] Remove Duplicates from Sorted List II
#
# https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
#
# algorithms
# Medium (32.70%)
# Likes:    924
# Dislikes: 79
# Total Accepted:    190.8K
# Total Submissions: 568.5K
# Testcase Example:  '[1,2,3,3,4,4,5]'
#
# Given a sorted linked list, delete all nodes that have duplicate numbers,
# leaving only distinct numbers from the original list.
#
# Example 1:
#
#
# Input: 1->2->3->3->4->4->5
# Output: 1->2->5
#
#
# Example 2:
#
#
# Input: 1->1->1->2->3
# Output: 2->3
#
#
#
# Definition for singly-linked list.


# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        pseudo_head = ListNode(0)
        pseudo_head.next = head

        last = pseudo_head
        cur = head
        cnt = 1  # the count of last.next.val
        while cur is not None:
            if cur.next is None or last.next.val != cur.next.val:
                if cnt > 1:
                    last.next = cur.next  # remove cur value
                else:
                    last = cur  # keep cur value
                cnt = 0
            cur = cur.next
            cnt += 1
        return pseudo_head.next
