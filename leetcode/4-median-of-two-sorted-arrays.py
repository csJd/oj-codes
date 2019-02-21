from bisect import bisect_left, bisect_right


class Solution:
    def findTheKth(self, nums1, nums2, k):
        """ find the kth num in two sorted list
        """
        le = 0
        ri = len(nums1) - 1
        while le <= ri:
            pos1 = (le + ri) // 2
            pos2_left = bisect_left(nums2, nums1[pos1])
            pos2_right = bisect_right(nums2, nums1[pos1])
            if pos1 + pos2_right < k:
                le = pos1 + 1
            elif pos1 + pos2_left > k:
                ri = pos1 - 1
            else:
                return nums1[pos1]
        return self.findTheKth(nums2, nums1, k)

    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        length = len(nums1) + len(nums2)
        num1 = self.findTheKth(nums1, nums2, (length)//2)
        num2 = num1
        if length % 2 == 0:
            num2 = self.findTheKth(nums1, nums2, (length-1)//2)
        return (num1 + num2) / 2


def main():
    solu = Solution()
    nums1 = [1]
    nums2 = []
    print(solu.findMedianSortedArrays(nums1, nums2))


if __name__ == "__main__":
    main()
