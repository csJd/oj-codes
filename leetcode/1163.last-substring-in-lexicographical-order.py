"""
1163. Last Substring in Lexicographical Order
https://leetcode.com/problems/last-substring-in-lexicographical-order/

Given a string s, return the last substring of s in lexicographical order.


Example 1:

Input: "abab"
Output: "bab"
Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba", "bab"]. The lexicographically maximum substring is "bab".
Example 2:

Input: "leetcode"
Output: "tcode"


Note:

1 <= s.length <= 10^5
s contains only lowercase English letters.
"""


class Solution:
    def lastSubstring(self, s: str) -> str:
        max_c = s[0]
        for c in s:
            if c > max_c:
                max_c = c

        max_sub = s[0]
        for i in range(len(s)):
            if s[i] == max_c:
                max_sub = max(max_sub, s[i:])

        return max_sub


def main():
    solu = Solution()
    print(solu.lastSubstring("leetcode"))
    print(solu.lastSubstring("bbbbbbbbbbbbbbbbb"))


if __name__ == "__main__":
    main()
