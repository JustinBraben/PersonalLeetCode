// DP Bottom up
class BottomUpSolution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 = 1;

        for (int i = 1; i < n; i++) {
            int temp = n1;
            n1 = n1 + n2;
            n2 = temp;
        }

        return n1;
    }
};

// DP tabular
class TabularSolution {
public:
    int climbStairs(int n){

        vector<int> tableStairs(n, 0);

        tableStairs[0] = 1;

        if (n == 1) return tableStairs[0];

        tableStairs[1] = 2;

        for (int i = 2; i < n; i++)
            tableStairs[i] = tableStairs[i - 2] + tableStairs[i - 1];

        return tableStairs[n - 1];
    }
};