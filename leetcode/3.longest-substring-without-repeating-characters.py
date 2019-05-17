# coding: utf-8

class Solution:

    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        pre_set = set()
        ans = 0
        for i in range(len(s)):
            if s[i] in pre_set:
                ind = i - len(pre_set)
                ind = ind + s[ind:i].index(s[i])
                pre_set = set(s[ind:i])
            pre_set.add(s[i])
            if len(pre_set) > ans:
                ans = len(pre_set)
        return ans


def main():
    solu = Solution()
    print(solu.lengthOfLongestSubstring("abac"))
    pass


if __name__ == '__main__':
    main()
    