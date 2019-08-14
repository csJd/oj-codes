"""
1156. Swap For Longest Repeated Character Substring
https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

Given a string text, we are allowed to swap two of the characters in the string. Find the length of the longest substring with repeated characters.



Example 1:

Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'. Then, the longest repeated character substring is "aaa", which its length is 3.
Example 2:

Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa", which its length is 6.
Example 3:

Input: text = "aaabbaaa"
Output: 4
Example 4:

Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa", length is 5.
Example 5:

Input: text = "abcdef"
Output: 1


Constraints:

1 <= text.length <= 20000
text consist of lowercase English characters only.

"""
from collections import defaultdict


class Solution:
    def maxRepOpt1(self, text: str) -> int:
        length = len(text)
        cnt = defaultdict(int)
        for c in text:
            cnt[c] += 1

        longest = 0
        for i, chr in enumerate(text):
            first_gap = True
            for j in range(i, length):
                if text[j] != text[i]:
                    if not first_gap:
                        # if cnt[chr] > j - i, there must have chr outside text[i:j]
                        # we can swap one to first gap
                        longest = max(longest, min(cnt[chr], j-i))
                        break
                    first_gap = False
                elif j == length - 1:
                    # try to swap a chr to text[i-1]
                    longest = max(longest, min(cnt[chr], j-i+1))

        return longest


def main():
    solu = Solution()
    print(solu.maxRepOpt1("aaabbaaa"))
    print(solu.maxRepOpt1("aaaaaa"))


if __name__ == "__main__":
    main()
