# coding: utf-8

class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        lists = ['' for i in range(numRows)]
        direction = 1 if numRows > 1 else 0
        pos = 0
        for c in s:
            lists[pos] += c
            pos += direction
            if pos == 0 or pos == numRows - 1:
                direction = -direction
        ret = ""
        for row in range(numRows):
            ret += lists[row]
        return ret


def main():
    solution = Solution()
    print(solution.convert("PAYPALISHIRING", numRows=4))
    print(solution.convert("AB", numRows=1))
    pass


if __name__ == '__main__':
    main()
