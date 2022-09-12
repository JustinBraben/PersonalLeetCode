class Solution {
public:

    vector<vector<int>> dp;

    int recurseChange(vector<int>& coins, int coinIndex, int amount) {
        if (coinIndex == 0) return 0;

        if (amount == 0) return 1;

        // If this is not a default value of -1
        if (dp[coinIndex][amount] != -1)
            return dp[coinIndex][amount];

        if (coins[coinIndex - 1] > amount) {
            dp[coinIndex][amount] = recurseChange(coins, coinIndex - 1, amount);
            return dp[coinIndex][amount];
        }

        dp[coinIndex][amount] = recurseChange(coins, coinIndex, amount - coins[coinIndex - 1]) + recurseChange(coins, coinIndex - 1, amount);

        return dp[coinIndex][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (amount == 0) return 1;
        if (n == 0) return 0;

        sort(coins.begin(), coins.end());

        dp.resize(n + 2, vector<int>(amount + 2, -1));

        dp[n][amount] = recurseChange(coins, n, amount);

        return dp[n][amount];
    }
};