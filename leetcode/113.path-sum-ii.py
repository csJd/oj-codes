#
# @lc app=leetcode id=113 lang=python3
#
# [113] Path Sum II
#
# https://leetcode.com/problems/path-sum-ii/description/
#
# algorithms
# Medium (40.22%)
# Likes:    981
# Dislikes: 35
# Total Accepted:    245.1K
# Total Submissions: 590.5K
# Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
#
# Given a binary tree and a sum, find all root-to-leaf paths where each path's
# sum equals the given sum.
#
# Note: A leaf is a node with no children.
#
# Example:
#
# Given the below binary tree and sum = 22,
#
#
# ⁠     5
# ⁠    / \
# ⁠   4   8
# ⁠  /   / \
# ⁠ 11  13  4
# ⁠/  \    / \
# 7    2  5   1
#
#
# Return:
#
#
# [
# ⁠  [5,4,11,2],
# ⁠  [5,8,4,5]
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
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root is None:
            return []

        result = list()

        def preorder(root, path, cur_sum):
            cur_sum += root.val
            if not (root.left or root.right):
                if cur_sum == sum:
                    result.append(path + [root.val])
                return

            if root.left:
                preorder(root.left, path + [root.val], cur_sum)
            if root.right:
                preorder(root.right, path + [root.val], cur_sum)

        preorder(root, [], 0)
        return result
