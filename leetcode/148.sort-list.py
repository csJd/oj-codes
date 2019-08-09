#
# @lc app=leetcode id=148 lang=python3
#
# [148] Sort List
#
# https://leetcode.com/problems/sort-list/description/
#
# algorithms
# Medium (34.83%)
# Likes:    1601
# Dislikes: 83
# Total Accepted:    197.3K
# Total Submissions: 540.6K
# Testcase Example:  '[4,2,1,3]'
#
# Sort a linked list in O(n log n) time using constant space complexity.
#
# Example 1:
#
#
# Input: 4->2->1->3
# Output: 1->2->3->4
#
#
# Example 2:
#
#
# Input: -1->5->3->4->0
# Output: -1->0->3->4->5
#
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def sortList(self, head: ListNode) -> ListNode:

        def merge_list(left, right):
            if (not right) or left.val < right.val:
                head = left
                left = left.next
            else:
                head = right
                right = right.next

            p = head
            while left and right:
                if left.val < right.val:
                    p.next = left
                    left = left.next
                else:
                    p.next = right
                    right = right.next
                p = p.next
            if left:
                p.next = left
            if right:
                p.next = right
            return head

        def merge_sort(list_head):
            if (not head) or (not list_head.next):
                return list_head
            # use two-pointer to find mid
            slow = fast = list_head
            while fast.next and fast.next.next:
                slow = slow.next
                fast = fast.next.next
            mid = slow

            right_head = mid.next
            mid.next = None
            left_sorted = merge_sort(list_head)
            right_sorted = merge_sort(right_head)
            return merge_list(left_sorted, right_sorted)

        return merge_sort(head)
