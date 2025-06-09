class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;

        for (int i = 0; i < n; i++) {
            result.push_back(current);

            // Try to go deeper (multiply by 10)
            if (current * 10 <= n) {
                current *= 10;
            }
            // Try to go to next sibling
            else if (current % 10 != 9 && current + 1 <= n) {
                current++;
            }
            // Backtrack and find next valid number
            else {
                // Remove trailing 9s and increment
                while ((current / 10) % 10 == 9) {
                    current /= 10;
                }
                current = current / 10 + 1;
            }
        }

        return result;
    }
};