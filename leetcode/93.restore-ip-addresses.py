#
# @lc app=leetcode id=93 lang=python3
#
# [93] Restore IP Addresses
#
# https://leetcode.com/problems/restore-ip-addresses/description/
#
# algorithms
# Medium (31.18%)
# Likes:    714
# Dislikes: 297
# Total Accepted:    146.5K
# Total Submissions: 457.7K
# Testcase Example:  '"25525511135"'
#
# Given a string containing only digits, restore it by returning all possible
# valid IP address combinations.
#
# Example:
#
#
# Input: "25525511135"
# Output: ["255.255.11.135", "255.255.111.35"]
#
#
#

from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        length = len(s)

        def dfs(cnt, cur, pos):
            if cnt > 2:
                if pos < length - 1 and s[pos] == '0':
                    return
                if int(s[pos:]) < 256:
                    result.append(cur+s[pos:])
                return

            for i in range(pos+1, length):
                if i - pos > 3:
                    break
                if i - pos > 1 and s[pos] == '0':
                    continue
                if int(s[pos:i]) < 256:
                    dfs(cnt+1, cur+s[pos:i]+'.', i)

        dfs(0, "", 0)
        return result


# def main():
#     solu = Solution()
#     print(solu.restoreIpAddresses("25525511135"))
#     print(solu.restoreIpAddresses("010010"))


# if __name__ == "__main__":
#     main()
