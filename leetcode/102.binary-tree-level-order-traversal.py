#
# @lc app=leetcode id=102 lang=python3
#
# [102] Binary Tree Level Order Traversal
#
# https://leetcode.com/problems/binary-tree-level-order-traversal/description/
#
# algorithms
# Medium (47.98%)
# Likes:    1642
# Dislikes: 44
# Total Accepted:    406.4K
# Total Submissions: 822.8K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, return the level order traversal of its nodes' values.
# (ie, from left to right, level by level).
#
#
# For example:
# Given binary tree [3,9,20,null,null,15,7],
#
# ⁠   3
# ⁠  / \
# ⁠ 9  20
# ⁠   /  \
# ⁠  15   7
#
#
#
# return its level order traversal as:
#
# [
# ⁠ [3],
# ⁠ [9,20],
# ⁠ [15,7]
# ]
#
#
#
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        result = [[]]
        queue = []
        queue.append((root, 0))
        cur_level = 0
        while queue:
            node, level = queue.pop(0)
            if level > cur_level:
                result.append([])
                cur_level += 1
            result[-1].append(node.val)
            if node.left:
                queue.append((node.left, cur_level + 1))
            if node.right:
                queue.append((node.right, cur_level + 1))
        return result
