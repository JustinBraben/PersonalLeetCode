class Solution {
public:
    int integerReplacement(int n) {
        // return n if n is 0
        if (n == 1) return 0;

        unsigned int res = INT_MAX;

        stack<pair<unsigned int, int>> sNum;
        sNum.push({ n, 0 });

        while (!sNum.empty()) {
            pair<unsigned int, int> temp = sNum.top();  // check value at top of stack
            sNum.pop();

            if (floor(log2(temp.first)) == log2(temp.first)) {
                res = min(res, (unsigned int)temp.second + (unsigned int)floor(log2(temp.first)));
            }

            if (temp.first > 1) {
                // Even case
                if (temp.first % 2 == 0) {
                    sNum.push({ temp.first / 2, temp.second + 1 });
                }
                // Odd case
                else {
                    sNum.push({ temp.first - 1, temp.second + 1 });
                    sNum.push({ temp.first + 1, temp.second + 1 });
                }
            }
            if (temp.first == 1)
                res = std::min(res, (unsigned int)temp.second);
        }

        return res;
    }
};