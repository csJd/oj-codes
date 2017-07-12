class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """

        def binSearch(iNums, key):
            l = m = 0
            r = len(iNums) - 1
            while l <= r:
                m = (l + r) >> 1
                if iNums[m][1] < key:
                    l = m + 1
                elif iNums[m][1] > key:
                    r = m - 1
                else:
                    return iNums[m][0]
            return -1

        iNums = list(enumerate(nums))
        iNums.sort(key=lambda x: x[1])
        for i in range(len(nums)):
            j = binSearch(iNums[i + 1:], target - iNums[i][1])
            if j >= 0:
                return sorted([iNums[i][0], j])

class BetterSolution:
     def twoSum(self, nums, target):
        dic = {}
        l = len(nums)
        for i in range(l):
            if nums[i] in dic:
                return [dic[nums[i]], i]
            else:
                dic[target - nums[i]] = i
