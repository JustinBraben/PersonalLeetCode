// Recursive Solution
class RecurseFibSolution {
public:
    int fib(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

// Memoized Recursive Solution
class MemoizedRecurseSolution {
public:

    int fibRecurse(int n, vector<int>& fibMemo) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (fibMemo[n] != -1) {
            return fibMemo[n];
        }
        fibMemo[n] = fibRecurse(n - 1, fibMemo) + fibRecurse(n - 2, fibMemo);
        return fibMemo[n];

    }

    int fib(int n) {

        vector<int> fibMemo(n + 1, -1);

        return fibRecurse(n, fibMemo);

    }
};

// Tabulated fast DP
class TabulatedSolution {
public:
    int fib(int n) {

        vector<int> fibMemo(n + 1, -1);

        fibMemo[0] = 0;

        if (n >= 1) fibMemo[1] = 1;

        for (int i = 2; i <= n; i++)
            fibMemo[i] = fibMemo[i - 1] + fibMemo[i - 2];

        return fibMemo[n];
    }
};