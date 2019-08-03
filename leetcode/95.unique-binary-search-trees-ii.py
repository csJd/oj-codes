#
# @lc app=leetcode id=95 lang=python3
#
# [95] Unique Binary Search Trees II
#
# https://leetcode.com/problems/unique-binary-search-trees-ii/description/
#
# algorithms
# Medium (35.36%)
# Likes:    1352
# Dislikes: 117
# Total Accepted:    146K
# Total Submissions: 401.2K
# Testcase Example:  '3'
#
# Given an integer n, generate all structurally unique BST's (binary search
# trees) that store values 1 ... n.
#
# Example:
#
#
# Input: 3
# Output:
# [
# [1,null,3,2],
# [3,2,null,1],
# [3,1,null,null,2],
# [2,1,3],
# [1,null,2,null,3]
# ]
# Explanation:
# The above output corresponds to the 5 unique BST's shown below:
#
# ⁠  1         3     3      2      1
# ⁠   \       /     /      / \      \
# ⁠    3     2     1      1   3      2
# ⁠   /     /       \                 \
# ⁠  2     1         2                 3
#
#
#
# Definition for a binary tree node.


# from copy import deepcopy
from typing import List


# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

#     def __repr__(self):
#         def preorder(node):
#             if node is None:
#                 return ['null']
#             left = preorder(node.left)
#             right = preorder(node.right)
#             return [node.val] + left + right
#         return str(preorder(self))


class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []

        def generateRangeTrees(le: int, ri: int) -> List[TreeNode]:
            if ri == le:
                return [None]
            if ri - le == 1:
                return [TreeNode(le)]
            result = []
            for mid in range(le, ri):
                left_trees = generateRangeTrees(le, mid)
                root = TreeNode(mid)
                right_trees = generateRangeTrees(mid+1, ri)
                for lt in left_trees:
                    for rt in right_trees:
                        root = TreeNode(mid)
                        root.left = lt
                        root.right = rt
                        result.append(root)
            return result
        return generateRangeTrees(1, n+1)


# def main():
#     solu = Solution()
#     res = solu.generateTrees(3)
#     print(res)


# if __name__ == "__main__":
#     main()
