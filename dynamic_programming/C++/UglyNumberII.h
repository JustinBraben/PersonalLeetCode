class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int> dp(n + 1); // init dp with n + 1 size
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1; // pointers for factors of 2, 3, 5

        for (int i = 2; i <= n; i++) {

            int f2 = 2 * dp[p2];
            int f3 = 3 * dp[p3];
            int f5 = 5 * dp[p5];

            int minAll = min(f5, min(f2, f3));

            dp[i] = minAll;

            if (minAll == f2)
                p2++;
            if (minAll == f3)
                p3++;
            if (minAll == f5)
                p5++;
        }

        return dp[n];
    }
};