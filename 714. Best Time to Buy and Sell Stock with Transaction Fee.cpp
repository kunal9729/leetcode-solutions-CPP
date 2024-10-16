class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0];
        int sell = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevBuy = buy;
            buy = max(buy, sell - prices[i]);
            sell = max(sell, prevBuy + prices[i] - fee);
        }

        return sell;
    }
};
