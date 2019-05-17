class Solution:
    def romanToInt(self, s: str) -> int:
        value_symbols = {
            1000: 'M', 900: 'CM',
            500: 'D', 400: 'CD',
            100: 'C', 90: 'XC',
            50: 'L', 40: 'XL',
            10: 'X', 9: 'IX',
            5: 'V', 4: 'IV',
            1: 'I'
        }
        ret = 0
        for value in value_symbols:
            symbol = value_symbols[value]
            while(s.startswith(symbol)):
                ret += value
                s = s[len(symbol):]
        return ret


if __name__ == "__main__":
    solu = Solution()
    print(solu.romanToInt("MCMXCIV"))
