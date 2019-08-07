#
# @lc app=leetcode id=142 lang=python
#
# [142] Linked List Cycle II
#
# https://leetcode.com/problems/linked-list-cycle-ii/description/
#
# algorithms
# Medium (31.64%)
# Likes:    1594
# Dislikes: 126
# Total Accepted:    229.7K
# Total Submissions: 697.5K
# Testcase Example:  '[3,2,0,-4]\n1'
#
# Given a linked list, return the node where the cycle begins. If there is no
# cycle, return null.
#
# To represent a cycle in the given linked list, we use an integer pos which
# represents the position (0-indexed) in the linked list where tail connects
# to. If pos is -1, then there is no cycle in the linked list.
#
# Note: Do not modify the linked list.
#
#
#
# Example 1:
#
#
# Input: head = [3,2,0,-4], pos = 1
# Output: tail connects to node index 1
# Explanation: There is a cycle in the linked list, where tail connects to the
# second node.
#
#
#
#
# Example 2:
#
#
# Input: head = [1,2], pos = 0
# Output: tail connects to node index 0
# Explanation: There is a cycle in the linked list, where tail connects to the
# first node.
#
#
#
#
# Example 3:
#
#
# Input: head = [1], pos = -1
# Output: no cycle
# Explanation: There is no cycle in the linked list.
#
#
#
#
#
#
# Follow-up:
# Can you solve it without using extra space?
#
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


'''
when p1(slow) meets p2(fast)
p1 walks k steps
p2 walks 2*k steps
cycle-length is C
`2*k - k = n*C => k = n*C`

then, let p1 start from head, let p2 start from the k-th node,
they will first meet at the cycle start node
'''


class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        p1 = p2 = head

        # find k
        while p2:
            if not p2.next:
                return None
            p1 = p1.next
            p2 = p2.next.next
            if p1 == p2:
                break
        if not p2:
            return None

        # find start node
        p1 = head
        while p1 != p2:
            p1 = p1.next
            p2 = p2.next

        return p1
