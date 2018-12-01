class Solution {
public:
    int maxProfit(vector<int> &prices) {
        const int size = prices.size();
        if (size < 2)
            return 0;
        int profit = 0, buy = -1;
        for (int i = 0; i < size - 1; ++i) {
            if (buy == -1) {
                if (prices[i] > prices[i + 1])
                    continue;
                buy = prices[i];
            } else {
                if (prices[i] <= prices[i + 1])
                    continue;
                profit += (prices[i] - buy);
                buy = -1;
            }
        }
        profit += (buy == -1 ? 0 : prices[size - 1] - buy);
        return profit;
    }
};
