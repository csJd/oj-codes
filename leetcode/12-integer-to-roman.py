class Solution:
    def intToRoman(self, num: int) -> str:
        value_symbols = {
            1000: 'M', 900: 'CM',
            500: 'D', 400: 'CD',
            100: 'C', 90: 'XC',
            50: 'L', 40: 'XL',
            10: 'X', 9: 'IX',
            5: 'V', 4: 'IV',
            1: 'I'
        }
        ret = ""
        for value in value_symbols:
            while(num >= value):
                ret += value_symbols[value]
                num -= value
        return ret


if __name__ == "__main__":
    solu = Solution()
    print(solu.intToRoman(1994))
    print(solu.intToRoman(3999))
