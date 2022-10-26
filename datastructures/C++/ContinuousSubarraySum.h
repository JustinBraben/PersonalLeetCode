class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        if (nums.size() < 2)
            return false;

        unordered_map<int, int> runningSumRemainder;

        runningSumRemainder[0] = -1;

        int runningSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];

            if (k != 0)
                runningSum = runningSum % k;

            // check if runningsum exists in the hash map
            if (runningSumRemainder.find(runningSum) != runningSumRemainder.end()) {
                if (i - runningSumRemainder[runningSum] > 1)
                    return true;
            }
            else {
                // otherwise if the current runningSum doesn't exist in the hash map, then store it as a maybe for later

                runningSumRemainder[runningSum] = i;
            }
        }

        return false;
    }
};