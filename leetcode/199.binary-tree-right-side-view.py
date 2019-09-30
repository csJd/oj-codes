#
# @lc app=leetcode id=199 lang=python3
#
# [199] Binary Tree Right Side View
#
# https://leetcode.com/problems/binary-tree-right-side-view/description/
#
# algorithms
# Medium (48.97%)
# Likes:    1216
# Dislikes: 59
# Total Accepted:    186.3K
# Total Submissions: 379.3K
# Testcase Example:  '[1,2,3,null,5,null,4]'
#
# Given a binary tree, imagine yourself standing on the right side of it,
# return the values of the nodes you can see ordered from top to bottom.
#
# Example:
#
#
# Input: [1,2,3,null,5,null,4]
# Output: [1, 3, 4]
# Explanation:
#
# ⁠  1            <---
# ⁠/   \
# 2     3         <---
# ⁠\     \
# ⁠ 5     4       <---
#
#


from collections import deque
# from typing import List


# # Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = list()
        if root is None:
            return res

        queue = deque()
        queue.append((root, 0))
        while queue:
            node, level = queue.popleft()
            if level >= len(res):
                res.append(node.val)
            else:
                res[level] = node.val

            if node.left:
                queue.append((node.left, level+1))
            if node.right:
                queue.append((node.right, level+1))

        return res
