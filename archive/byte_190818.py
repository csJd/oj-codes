# 有一个乱序正整数数组（含重复），寻找第一个未出现的正整数
# LeetCode 41，https://leetcode.com/problems/first-missing-positive/

from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.append(0)
        length = len(nums)

        for i in range(length):
            while 0 <= nums[i] < length and nums[i] != i and nums[nums[i]] != nums[i]:
                # swap nums[i] to position nums[i]
                num = nums[i]
                # cannot be `nums[i], nums[nums[i]] = nums[nums[i]], nums[i]`
                nums[i], nums[num] = nums[num], nums[i]

        for i in range(length):
            if nums[i] != i:
                return i
        return length


def main():
    # arr = list(map(int, input()))
    solu = Solution()
    print(solu.firstMissingPositive([7, 8, 9, 11, 12]))
    print(solu.firstMissingPositive([3, 4, 1, 1]))
    print(solu.firstMissingPositive([1, 1, 1, 4]))


if __name__ == "__main__":
    main()
