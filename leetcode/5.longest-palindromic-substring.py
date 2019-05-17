class Solution:

    def isPalindrome(self, s, left, right, memory):
        if left >= right:
            return 1
        if memory[left][right] > -1:
            return memory[left][right]
        elif s[left] != s[right]:
            memory[left][right] = 0
        else:
            memory[left][right] = self.isPalindrome(s, left+1, right-1, memory)
        return memory[left][right]

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        start, longest = 0, 0
        memory = [[-1 for i in range(length)] for j in range(length)]
        for left in range(length):
            for right in range(left, length):
                if self.isPalindrome(s, left, right, memory) and right - left + 1 > longest:
                    start, longest = left, right - left + 1
        return s[start:start+longest]
