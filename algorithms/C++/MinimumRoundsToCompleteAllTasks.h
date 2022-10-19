class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        unordered_map<int, int> roundMap;

        for (auto num : tasks)
            roundMap[num]++;

        int res = 0;

        for (auto entry : roundMap) {
            if (entry.second == 1)
                return -1;
            else {

                if (entry.second % 3 == 0)
                    res += entry.second / 3;
                else
                    res += (entry.second / 3) + 1;
            }
        }

        return res;
    }
};