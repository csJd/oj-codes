#
# @lc app=leetcode id=152 lang=python3
#
# [152] Maximum Product Subarray
#
# https://leetcode.com/problems/maximum-product-subarray/description/
#
# algorithms
# Medium (28.95%)
# Likes:    2328
# Dislikes: 111
# Total Accepted:    228.1K
# Total Submissions: 767.4K
# Testcase Example:  '[2,3,-2,4]'
#
# Given an integer array nums, find the contiguous subarray within an array
# (containing at least one number) which has the largest product.
#
# Example 1:
#
#
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
#
#
# Example 2:
#
#
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
#
#

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ans = maxv = minv = nums[0]
        for num in nums[1:]:
            if num < 0:
                minv, maxv = maxv, minv
            maxv = max(num, num * maxv)
            minv = min(num, num * minv)
            ans = max(ans, maxv)

        return ans

    def maxProductMy(self, nums: List[int]) -> int:
        """
        In a subarray without zero, if there are odd number of negative
        numbers, the max procuct will be the product of remove the right
        most negative number and the right ones, or the product of remove
        the left most negative number and the left ones.
        """
        length = len(nums)
        if length == 1:
            return nums[0]

        # record index of the left most nagative number and the right most
        # negative number in current no-zero segment
        left = right = 0
        # record the number of negative numbers in current segment
        n_negs = 0
        ans = nums[0]
        accu_prod = [0] * length

        for i in range(0, length+1):
            if i == length or nums[i] == 0:
                if i < length and ans < 0:
                    ans = 0
                if n_negs % 2 == 0:
                    ans = max(ans, accu_prod[i-1])
                # there add odd number of nagative numbers
                else:
                    if i - 1 > left:
                        # remove left part until leftmost negative number
                        ans = max(ans, accu_prod[i-1] // accu_prod[left])
                    if right > 0:
                        # remove right part until rightmost negative number
                        ans = max(ans, accu_prod[right-1])

                n_negs = 0

            else:
                if nums[i] < 0:
                    if n_negs == 0:
                        left = i
                    right = i
                    n_negs += 1
                if i == 0 or accu_prod[i-1] == 0:
                    accu_prod[i] = nums[i]
                else:
                    accu_prod[i] = accu_prod[i-1] * nums[i]

        return ans


def main():
    solu = Solution()
    print(solu.maxProduct([2, 3, -2, 4]))
    print(solu.maxProduct([-3, 0, 1, -4]))
    print(solu.maxProduct([-2]))
    print(solu.maxProduct([-2, 0, -1]))
    print(solu.maxProduct([-2, -3, -1]))
    print(solu.maxProduct([-2, 1]))


if __name__ == "__main__":
    main()
