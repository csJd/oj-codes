#
# @lc app=leetcode id=138 lang=python3
#
# [138] Copy List with Random Pointer
#
# https://leetcode.com/problems/copy-list-with-random-pointer/description/
#
# algorithms
# Medium (26.62%)
# Likes:    1735
# Dislikes: 461
# Total Accepted:    264.2K
# Total Submissions: 939.5K
# Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
#
# A linked list is given such that each node contains an additional random
# pointer which could point to any node in the list or null.
#
# Return a deep copy of the list.
#
#
#
# Example 1:
#
#
#
#
# Input:
#
# {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
#
# Explanation:
# Node 1's value is 1, both of its next and random pointer points to Node 2.
# Node 2's value is 2, its next pointer points to null and its random pointer
# points to itself.
#
#
#
#
# Note:
#
#
# You must return the copy of the given head as a reference to the cloned
# list.
#
#
#
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""

from collections import defaultdict


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        cpy = defaultdict(lambda: Node(0, None, None))
        node = head
        cpy[None] = None  # important, or cpy[None] will be Node(0)
        while node:
            cpy[node].val = node.val
            cpy[node].next = cpy[node.next]
            cpy[node].random = cpy[node.random]
            node = node.next

        return cpy[head]

    # worse solution
    def copyRandomList(self, head: 'Node') -> 'Node':
        def copy_next(node):
            if node is None:
                return
            copy_node = Node(node.val, None, None)
            copy_node.next = copy_next(node.next)
            return copy_node
        copy_head = copy_next(head)

        # copy random
        node1 = head
        node2 = copy_head
        while node2:
            random = node1.random
            if random:
                p1, p2 = head, copy_head
                while p1:
                    if p1 is random:
                        node2.random = p2
                        break
                    p1 = p1.next
                    p2 = p2.next
            node1 = node1.next
            node2 = node2.next

        return copy_head
