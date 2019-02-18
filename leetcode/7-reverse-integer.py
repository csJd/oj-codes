# coding: utf-8
class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = 1
        if x < 0:
            x = -x
            sign = -1
        ret = 0
        while x:
            ret = ret * 10 + x % 10
            x //= 10
        if ret < -(1 << 31) or ret >= 1 << 31:
            ret = 0
        return sign * ret


def main():
    print(solution.reverse(1))
    print(solution.reverse(-1281))
    print(solution.reverse(1463847412))
    pass


if __name__ == '__main__':
    solution = Solution()
    main()
