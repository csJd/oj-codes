#
# @lc app=leetcode id=96 lang=python3
#
# [96] Unique Binary Search Trees
#
# https://leetcode.com/problems/unique-binary-search-trees/description/
#
# algorithms
# Medium (46.05%)
# Likes:    1866
# Dislikes: 73
# Total Accepted:    210.3K
# Total Submissions: 447.2K
# Testcase Example:  '3'
#
# Given n, how many structurally unique BST's (binary search trees) that store
# values 1 ... n?
#
# Example:
#
#
# Input: 3
# Output: 5
# Explanation:
# Given n = 3, there are a total of 5 unique BST's:
#
# ⁠  1         3     3      2      1
# ⁠   \       /     /      / \      \
# ⁠    3     2     1      1   3      2
# ⁠   /     /       \                 \
# ⁠  2     1         2                 3
#
#
#


class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n+1)
        dp[0] = dp[1] = 1

        def dfs(k):
            if dp[k] > 0:
                return dp[k]
            res = 0
            # use mid as root
            for mid in range(k):
                res += dfs(mid) * dfs(k-1-mid)
            dp[k] = res
            return res
        return dfs(n)


# def main():
#     solu = Solution()
#     print(solu.numTrees(3))
#     print(solu.numTrees(2))


# if __name__ == "__main__":
#     main()
