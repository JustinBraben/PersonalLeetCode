class Solution {
public:

    int minMutation(string start, string end, vector<string>& bank) {

        if (bank.size() < 1)
            return -1;

        if (find(bank.begin(), bank.end(), end) == bank.end())
            return -1;

        map<string, int> dist;
        dist[start] = 0;
        queue<string> q;
        q.push(start);

        while (q.size()) {

            auto curVal = q.front();
            q.pop();

            for (auto candidate : bank) {

                if (dist.count(candidate))
                    continue;

                int count = 0;

                for (int i = 0; i < 8; i++) {

                    if (curVal[i] != candidate[i])
                        count++;

                }

                if (count == 1) {
                    dist[candidate] = dist[curVal] + 1;
                    q.push(candidate);
                }

            }
        }
        if (dist.count(end))
            return dist[end];
        else return -1;
    }
};