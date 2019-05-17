class Solution:
    def myAtoi(self, s: 'str') -> 'int':
        s = s.lstrip(' ')
        if s == '' or s[0] not in '+-0123456789':
            return 0
        end = len(s)
        for ind, c in enumerate(s):
            if ind == 0:
                continue
            if not c.isdigit():
                end = ind
                break
        s = s[:end]
        if s == '+' or s == '-':
            return 0
        res = int(s)
        if res < -1 << 31:
            res = -1 << 31
        elif res >= 1 << 31:
            res = (1 << 31) - 1
        return res
