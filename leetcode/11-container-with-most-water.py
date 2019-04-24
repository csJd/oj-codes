class Solution:
    def maxArea(self, height):
        left = 0
        right = len(height) - 1
        max_area = 0
        while(left < right):
            if height[left] < height[right]:
                h = height[left]
                left += 1
            else:
                h = height[right]
                right -= 1
            if (right - left + 1) * h > max_area:
                max_area = (right-left+1) * h
        return max_area


if __name__ == "__main__":
    solu = Solution()
    print(solu.maxArea([1, 8, 6, 2, 5, 4, 8, 3, 7]))
