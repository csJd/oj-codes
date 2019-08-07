#
# @lc app=leetcode id=135 lang=python3
#
# [135] Candy
#
# https://leetcode.com/problems/candy/description/
#
# algorithms
# Hard (28.14%)
# Likes:    559
# Dislikes: 125
# Total Accepted:    106.9K
# Total Submissions: 369.9K
# Testcase Example:  '[1,0,2]'
#
# There are N children standing in a line. Each child is assigned a rating
# value.
#
# You are giving candies to these children subjected to the following
# requirements:
#
#
# Each child must have at least one candy.
# Children with a higher rating get more candies than their neighbors.
#
#
# What is the minimum candies you must give?
#
# Example 1:
#
#
# Input: [1,0,2]
# Output: 5
# Explanation: You can allocate to the first, second and third child with 2, 1,
# 2 candies respectively.
#
#
# Example 2:
#
#
# Input: [1,2,2]
# Output: 4
# Explanation: You can allocate to the first, second and third child with 1, 2,
# 1 candies respectively.
# ⁠            The third child gets 1 candy because it satisfies the above two
# conditions.
#
#
#

from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        n_children = len(ratings)
        left = [1] * n_children
        for i in range(1, n_children):
            if ratings[i] > ratings[i-1]:
                left[i] = left[i-1] + 1

        ans = left[-1]
        right = [1] * n_children
        for i in range(n_children - 2, -1, -1):
            if ratings[i] > ratings[i+1]:
                right[i] = right[i+1] + 1
            ans += max(left[i], right[i])

        return ans


def main():
    solu = Solution()
    print(solu.candy([1, 2, 2]))


if __name__ == "__main__":
    main()
