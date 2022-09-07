class Solution {
public:

    int findTotalCharsInString(const string& str, const string& sub) {
        if (sub.length() == 0) return 0;
        int count = 0;
        for (size_t offset = str.find(sub); offset != string::npos;
            offset = str.find(sub, offset + sub.length()))
        {
            ++count;
        }
        return count;
    }

    vector<string> generateParenthesis(int n) {
        if (n <= 0) return { "" };

        vector<string> res;
        queue<string> qCandidates;
        qCandidates.push("(");

        while (!qCandidates.empty()) {

            // can add more "(" to your string
            if (findTotalCharsInString(qCandidates.front(), "(") <= n) {

                string newVal1 = qCandidates.front() + "(";
                string newVal2 = qCandidates.front() + ")";

                if (findTotalCharsInString(newVal1, "(") <= n)
                    qCandidates.push(newVal1);
                if (findTotalCharsInString(newVal2, "(") >= findTotalCharsInString(newVal2, ")"))
                    qCandidates.push(newVal2);

                qCandidates.pop();
            }

            while (!qCandidates.empty() && qCandidates.front().length() == n * 2) {
                res.push_back(qCandidates.front());
                qCandidates.pop();
            }
        }

        return res;
    }
};