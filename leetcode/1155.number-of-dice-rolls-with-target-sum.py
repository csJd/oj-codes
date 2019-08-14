"""
1155. Number of Dice Rolls With Target Sum https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

You have d dice, and each die has f faces numbered 1, 2, ..., f.

Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.



Example 1:

Input: d = 1, f = 6, target = 3
Output: 1
Explanation:
You throw one die with 6 faces.  There is only one way to get a sum of 3.
Example 2:

Input: d = 2, f = 6, target = 7
Output: 6
Explanation:
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: d = 2, f = 5, target = 10
Output: 1
Explanation:
You throw two dice, each with 5 faces.  There is only one way to get a sum of 10: 5+5.
Example 4:

Input: d = 1, f = 2, target = 3
Output: 0
Explanation:
You throw one die with 2 faces.  There is no way to get a sum of 3.
Example 5:

Input: d = 30, f = 30, target = 500
Output: 222616187
Explanation:
The answer must be returned modulo 10^9 + 7.


Constraints:

1 <= d, f <= 30
1 <= target <= 1000

"""


class Solution:
    def numRollsToTarget(self, d: int, f: int, target: int) -> int:
        MOD = 10**9 + 7
        dp = [[0] * (target+1) for i in range(target+1)]
        dp[0][0] = 1
        for i in range(d):
            # the (i+1)-th dice rolls j
            for j in range(1, f+1):
                for k in range(target-j+1):
                    dp[i+1][k+j] = (dp[i+1][k+j] + dp[i][k]) % MOD

        return dp[d][target]

    def numRollsToTargetOld(self, d: int, f: int, target: int) -> int:
        MOD = int(1e9 + 7)
        dp = [[-1] * (target+1) for i in range(d + 1)]

        def dfs(d, t):
            if (d * f < t or t < d):
                return 0
            if dp[d][t] >= 0:
                return dp[d][t]
            if d == 1:
                return 1
            else:
                dp[d][t] = 0
                # the d-th dish rolls from 1 to f
                for r in range(t - f, t):
                    dp[d][t] = (dp[d][t] + dfs(d-1, r)) % MOD
            return dp[d][t]

        return dfs(d, target)


def main():
    solu = Solution()
    print(solu.numRollsToTarget(2, 5, 10))
    print(solu.numRollsToTarget(2, 6, 7))
    print(solu.numRollsToTarget(30, 30, 500))


if __name__ == "__main__":
    main()
