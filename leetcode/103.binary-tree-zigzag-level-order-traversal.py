#
# @lc app=leetcode id=103 lang=python3
#
# [103] Binary Tree Zigzag Level Order Traversal
#
# https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
#
# algorithms
# Medium (41.30%)
# Likes:    1072
# Dislikes: 63
# Total Accepted:    235.9K
# Total Submissions: 554.6K
# Testcase Example:  '[3,9,20,null,null,15,7]'
#
# Given a binary tree, return the zigzag level order traversal of its nodes'
# values. (ie, from left to right, then right to left for the next level and
# alternate between).
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
# return its zigzag level order traversal as:
#
# [
# ⁠ [3],
# ⁠ [20,9],
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
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        result = []
        queue = []
        queue.append((root, 0))
        cur_level = -1
        while queue:
            node, level = queue.pop(0)
            if level > cur_level:
                result.append([])
                cur_level += 1

            if cur_level % 2 == 0:
                result[-1].append(node.val)
            else:
                result[-1].insert(0, node.val)

            if node.left:
                queue.append((node.left, cur_level + 1))
            if node.right:
                queue.append((node.right, cur_level + 1))
        return result
