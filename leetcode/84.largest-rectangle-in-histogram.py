#
# @lc app=leetcode id=84 lang=python3
#
# [84] Largest Rectangle in Histogram
#
# https://leetcode.com/problems/largest-rectangle-in-histogram/description/
#
# algorithms
# Hard (30.98%)
# Likes:    2078
# Dislikes: 56
# Total Accepted:    184.7K
# Total Submissions: 582.5K
# Testcase Example:  '[2,1,5,6,2,3]'
#
# Given n non-negative integers representing the histogram's bar height where
# the width of each bar is 1, find the area of largest rectangle in the
# histogram.
#
# Above is a histogram where width of each bar is 1, given height =
# [2,1,5,6,2,3].
#
# The largest rectangle is shown in the shaded area, which has area = 10
# unit.
#
# Example:
#
# Input: [2,1,5,6,2,3]
# Output: 10
#
#
#

# [单调栈](https://oi-wiki.org/ds/monotonous-stack/) 的应用
# > 将一个元素插入单调栈时，为了维护栈的单调性，需要在保证将该元素插入到栈顶后整个栈满足单调性的前提下弹出最少的元素。
# 非递减单调栈可以保证栈中相邻在原始输入序列中构成的区间也是单调的，利用这个性质，栈中每个元素都可以得到以自己的值为高，以栈底方向相邻元素和栈顶元素之间的距离为宽的一个矩形，这个矩形就是包含该元素并以其高度为高的最大矩形。

# 每当有元素出栈时，就可以以当前待入栈元素的在原始序列下标减去 1 作为右端点 `right`（每次入栈时第一个栈顶元素的下标肯定为 `right - 1`），出栈后的栈顶元素的下标加上 1 作为左端点 `left` ，得到以出栈元素的值为高度的一个矩形 `height * (right - left + 1)`，记录下最大值就是答案了。
# 为了保证每个元素都能出栈，还需要在队列最后插入值为 0 的一个元素；同理，为了保持栈非空，初始在栈中放了高度为 0 的元素。


from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        mono_stack = [(-1, 0)]  # monotonically ascending stack, (index, height)
        largest_area = 0
        for i, h in enumerate(heights + [0]):  # add zero-value element to the last
            right = i - 1
            while h < mono_stack[-1][1]:
                height = mono_stack.pop()[1]
                left = mono_stack[-1][0] + 1
                largest_area = max(largest_area, (right - left + 1) * height)
            mono_stack.append((i, h))

        return largest_area


# def main():
#     solu = Solution()
#     print(solu.largestRectangleArea([2, 1, 5, 6, 2, 3]))  # 10
#     print(solu.largestRectangleArea([1, 2, 3, 4, 5]))     # 9
#     print(solu.largestRectangleArea([2, 1, 2]))           # 3


# if __name__ == "__main__":
#     main()
