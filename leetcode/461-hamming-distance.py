class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        ret = 0
        z = x^y
        while z:
            ret += z&1
            z >>= 1
        return ret
