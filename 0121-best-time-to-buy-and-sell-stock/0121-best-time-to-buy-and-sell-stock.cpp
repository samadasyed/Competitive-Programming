class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;                       // buy
        int right = 1;                      // sell
        int biggestStockDiff = 0;

        while (right < (int)prices.size()) {
            if (prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                biggestStockDiff = max(biggestStockDiff, profit);
            } else {
                // Found a cheaper price, better day to buy
                left = right;
            }
            right++;
        }

        return biggestStockDiff;
    }
};
