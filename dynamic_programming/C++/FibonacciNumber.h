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