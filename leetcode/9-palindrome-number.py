# coding: utf-8


class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        x = str(x)
        for i in range(len(x)):
            if x[i] != x[-1-i]:
                return False
        return True


def main():
    solu = Solution()
    print(solu.isPalindrome(-121))
    pass


if __name__ == '__main__':
    main()
