#
# @lc app=leetcode id=99 lang=python3
#
# [99] Recover Binary Search Tree
#
# https://leetcode.com/problems/recover-binary-search-tree/description/
#
# algorithms
# Hard (34.33%)
# Likes:    843
# Dislikes: 48
# Total Accepted:    123.5K
# Total Submissions: 350.7K
# Testcase Example:  '[1,3,null,null,2]'
#
# Two elements of a binary search tree (BST) are swapped by mistake.
#
# Recover the tree without changing its structure.
#
# Example 1:
#
#
# Input: [1,3,null,null,2]
#
#   1
#  /
# 3
#  \
#   2
#
# Output: [3,1,null,null,2]
#
#   3
#  /
# 1
#  \
#   2
#
#
# Example 2:
#
#
# Input: [3,1,4,null,null,2]
#
#   3
#  / \
# 1   4
#    /
#   2
#
# Output: [2,1,4,null,null,3]
#
#   2
#  / \
# 1   4
#    /
#   3
#
#
# Follow up:
#
#
# A solution using O(n) space is pretty straight forward.
# Could you devise a constant space solution?
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
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        # the leftmost un-order node and the rightmost one are the two elments.
        left = right = last = None
        found = False

        def inorder(node):
            nonlocal left, right, last, found
            if found or node is None:
                return
            inorder(node.left)
            if last and node.val < last.val:
                if not left:
                    left = last
                if right:
                    found = True
                right = node
            last = node
            inorder(node.right)

        inorder(root)
        left.val, right.val = right.val, left.val
