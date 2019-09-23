#
# @lc app=leetcode id=188 lang=python3
#
# [188] Best Time to Buy and Sell Stock IV
#
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
#
# algorithms
# Hard (26.73%)
# Likes:    857
# Dislikes: 56
# Total Accepted:    95.3K
# Total Submissions: 356.3K
# Testcase Example:  '2\n[2,4,1]'
#
# Say you have an array for which the i-th element is the price of a given
# stock on day i.
#
# Design an algorithm to find the maximum profit. You may complete at most k
# transactions.
#
# Note:
# You may not engage in multiple transactions at the same time (ie, you must
# sell the stock before you buy again).
#
# Example 1:
#
#
# Input: [2,4,1], k = 2
# Output: 2
# Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit =
# 4-2 = 2.
#
#
# Example 2:
#
#
# Input: [3,2,6,5,0,3], k = 2
# Output: 7
# Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit =
# 6-2 = 4.
# Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
# 3.
#

from typing import List


class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n_days = len(prices)
        if n_days == 0:
            return 0
        if k >= n_days // 2:
            # quick solve if k is large enough
            ans = 0
            for i in range(1, n_days):
                if prices[i] > prices[i-1]:
                    ans += prices[i] - prices[i-1]
            return ans

        # dp[i][j] represents maxProfit(i, prices[:j+1])
        dp = [[0] * n_days for i in range(k+1)]
        maxt = [0] * n_days
        maxt[0] = -prices[0]

        for i in range(1, k+1):
            for j in range(1, n_days):
                # record max({dp[i-1][t] - prices[t+1]}), t in range(-1, j)
                maxt[j] = max(maxt[j-1], dp[i-1][j-1] - prices[j])
                # sell on the j-th day or not sell
                # if sell on the j-th day,
                # dp[i][j] = max([dp[i-1][t] + prices[j] - prices[t+1]]
                #                  for t in range(-1, j)
                # if not sell, dp[i][j] = dp[i][j-1]
                dp[i][j] = max(maxt[j] + prices[j], dp[i][j-1])

        return dp[k][n_days-1]


def main():
    solu = Solution()
    print(solu.maxProfit(1, [3, 2, 6, 5, 0, 3]))
    print(solu.maxProfit(2, [3, 2, 6, 5, 0, 3]))


if __name__ == "__main__":
    main()
