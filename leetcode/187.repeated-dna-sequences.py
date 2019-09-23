#
# @lc app=leetcode id=187 lang=python3
#
# [187] Repeated DNA Sequences
#
# https://leetcode.com/problems/repeated-dna-sequences/description/
#
# algorithms
# Medium (36.64%)
# Likes:    482
# Dislikes: 198
# Total Accepted:    133K
# Total Submissions: 362.4K
# Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
#
# All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
# for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
# identify repeated sequences within the DNA.
#
# Write a function to find all the 10-letter-long sequences (substrings) that
# occur more than once in a DNA molecule.
#
# Example:
#
#
# Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
#
# Output: ["AAAAACCCCC", "CCCCCAAAAA"]
#
#
#


from typing import List


class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        length = len(s)
        dic = dict()
        ans = list()
        for i in range(length - 9):
            substr = s[i:i+10]
            if substr in dic:
                dic[substr] += 1
                if dic[substr] == 2:
                    ans.append(substr)
            else:
                dic[substr] = 1
        return ans


if __name__ == "__main__":
    solu = Solution()
    print(solu.findRepeatedDnaSequences("AAAAAAAAAAA"))
