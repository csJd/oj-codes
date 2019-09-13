#
# @lc app=leetcode id=160 lang=python
#
# [160] Intersection of Two Linked Lists
#
# https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#
# algorithms
# Easy (33.31%)
# Likes:    2293
# Dislikes: 212
# Total Accepted:    327.8K
# Total Submissions: 938K
# Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
#
# Write a program to find the node at which the intersection of two singly
# linked lists begins.
#
# For example, the following two linked lists:
#
#
# begin to intersect at node c1.
#
#
#
# Example 1:
#
#
#
# Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA =
# 2, skipB = 3
# Output: Reference of the node with value = 8
# Input Explanation: The intersected node's value is 8 (note that this must not
# be 0 if the two lists intersect). From the head of A, it reads as
# [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes
# before the intersected node in A; There are 3 nodes before the intersected
# node in B.
#
#
#
# Example 2:
#
#
#
# Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3,
# skipB = 1
# Output: Reference of the node with value = 2
# Input Explanation: The intersected node's value is 2 (note that this must not
# be 0 if the two lists intersect). From the head of A, it reads as
# [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes
# before the intersected node in A; There are 1 node before the intersected
# node in B.
#
#
#
#
# Example 3:
#
#
#
# Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
# Output: null
# Input Explanation: From the head of A, it reads as [2,6,4]. From the head of
# B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must
# be 0, while skipA and skipB can be arbitrary values.
# Explanation: The two lists do not intersect, so return null.
#
#
#
#
# Notes:
#
#
# If the two linked lists have no intersection at all, return null.
# The linked lists must retain their original structure after the function
# returns.
# You may assume there are no cycles anywhere in the entire linked
# structure.
# Your code should preferably run in O(n) time and use only O(1) memory.
#
#
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if not (headA and headB):
            return None
        pa = headA
        pb = headB
        while pa != pb:
            pa = pa.next
            pb = pb.next
            if not pa:
                pa = headB
                headB = None
            if not pb:
                pb = headA
                headA = None
        return pa

    def getIntersectionNodeMy(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        length_a = length_b = 0
        p = headA
        while p:
            length_a += 1
            p = p.next

        p = headB
        while p:
            length_b += 1
            p = p.next

        while length_a > length_b:
            headA = headA.next
            length_a -= 1

        while length_b > length_a:
            headB = headB.next
            length_b -= 1

        while headA and headA is not headB:
            headA = headA.next
            headB = headB.next

        return headA
