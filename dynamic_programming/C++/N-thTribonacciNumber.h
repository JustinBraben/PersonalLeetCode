class RecurseSolution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        return tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }
};

class MemoizedSolution {
public:
    int recurseTribonacci(int n, vector<int>& tribMemo) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        if (tribMemo[n] != -1)
            return tribMemo[n];
        return tribMemo[n] = recurseTribonacci(n - 3, tribMemo) + recurseTribonacci(n - 2, tribMemo) + recurseTribonacci(n - 1, tribMemo);
    }

    int tribonacci(int n) {
        vector<int> tribMemo(n + 1, -1);
        return recurseTribonacci(n, tribMemo);
    }
};

// Best on memory
class DPOnePassSolution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        int t0 = 0, t1 = 1, t2 = 1;
        for (int i = 0; i < n - 2; i++) {
            // Your current index will be relative to what your t(n - 3) + t(n - 2) + t(n - 1)
            // So these are adjusting your t(n - 3) + t(n - 2) + t(n - 1) values as you travel up 
            // the sequence
            int tn = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = tn;
        }
        return t2;
    }
};

// Best on runtime
class FastMemoSolution {
public:
    int tribonacci(int n) {
        vector<int> tribMemo(n + 1, -1);
        for (int i = 0; i < n + 1; i++) {
            if (i == 0 || i == 1) {
                tribMemo[i] = i;
            }
            else if (i == 2) {
                tribMemo[i] = 1;
            }
            else {
                tribMemo[i] = tribMemo[i - 1] + tribMemo[i - 2] + tribMemo[i - 3];
            }
        }
        return tribMemo[n];
    }
};