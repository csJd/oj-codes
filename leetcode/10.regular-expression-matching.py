class Solution:

    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        s = ' ' + s
        p = ' ' + p
        ls = len(s)
        lp = len(p)
        dp = [[False for j in range(lp+1)] for i in range(ls+1)]
        dp[0][0] = True
        for i in range(ls):
            for j in range(lp):
                if i > 0 and j > 0 and (s[i] == p[j] or p[j] == '.'):
                    dp[i][j] = dp[i][j] or dp[i-1][j-1]
                elif p[j] == '*' and j > 1:
                    dp[i][j] = dp[i][j] or dp[i][j-2]
                    if i > 0 and (s[i] == p[j-1] or p[j-1] == '.'):
                        dp[i][j] = dp[i][j] or dp[i-1][j]
        # print(dp)
        return dp[ls-1][lp-1]


if __name__ == "__main__":
    solu = Solution()
    print(solu.isMatch("aa", "a*"))
