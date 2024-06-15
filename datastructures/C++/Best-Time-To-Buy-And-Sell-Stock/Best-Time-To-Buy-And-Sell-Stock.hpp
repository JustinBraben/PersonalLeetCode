class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxPro = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            // find the minimum of minimum price vs value at current index
            minPrice = min(minPrice, prices[i]);

            // Find the max profit of currrent max profit vs current index - minimum price 
            // will return the highest possible profit
            maxPro = max(maxPro, prices[i] - minPrice);
        }

        return maxPro;
    }
};