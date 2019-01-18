#1 DP
class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        size = len(prices)
        if size == 0:
            return 0
        hold = [0] * size
        unhold = [0] * size
        hold[0] = -prices[0]
        for i in range(1, size):
            hold[i] = max(hold[i-1], unhold[i-1] - prices[i])
            unhold[i] = max(unhold[i-1], hold[i-1] + prices[i] - fee)
        return unhold[size-1]

#2 Greed
class Solution:
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        size = len(prices)
        if size < 2:
            return 0
        profit = 0
        cost = prices[0]
        for i in range(1, size):
            if prices[i] < cost:
                cost = prices[i]
            elif prices[i] - fee > cost:
                profit += prices[i] - fee - cost
                cost = prices[i] - fee
        return profit
