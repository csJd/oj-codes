#
# @lc app=leetcode id=124 lang=python3
#
# [124] Binary Tree Maximum Path Sum
#
# https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
#
# algorithms
# Hard (30.49%)
# Likes:    1786
# Dislikes: 134
# Total Accepted:    207.9K
# Total Submissions: 681.7K
# Testcase Example:  '[1,2,3]'
#
# Given a non-empty binary tree, find the maximum path sum.
#
# For this problem, a path is defined as any sequence of nodes from some
# starting node to any node in the tree along the parent-child connections. The
# path must contain at least one node and does not need to go through the
# root.
#
# Example 1:
#
#
# Input: [1,2,3]
#
# ⁠      1
# ⁠     / \
# ⁠    2   3
#
# Output: 6
#
#
# Example 2:
#
#
# Input: [-10,9,20,null,null,15,7]
#
# -10
# / \
# 9  20
# /  \
# 15   7
#
# Output: 42
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
    def maxPathSum(self, root: TreeNode) -> int:
        max_sum = root.val if root else 0

        def max_down(node):
            nonlocal max_sum
            if not node:
                return 0
            left_max = max(0, max_down(node.left))
            right_max = max(0, max_down(node.right))
            max_sum = max(max_sum, node.val + left_max + right_max)
            return node.val + max(left_max, right_max)

        max_down(root)
        return max_sum
