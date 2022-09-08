class Solution {
public:
    string convert(std::string s, int numRows) {

        if (s.length() <= 1) return s;

        if (numRows <= 1) return s;

        std::vector<std::string> vecBuilder(numRows);
        std::string res = "";

        int index = 0;
        int count = 0;

        while (index < s.length()) {

            if (index % (numRows - 1) == 0) {

                int i = index;
                count++;
                int rBound = index + (numRows - 1);

                while (i < s.length() && i <= rBound) {
                    if (count > 1)
                        vecBuilder[(i - index) % numRows] += s[i];
                    else
                        vecBuilder[i] += s[i];
                    i++;
                }

                index += numRows;
            }
            else {
                int desiredVec = index % (numRows - 1);
                vecBuilder[(numRows - 1) - desiredVec] += s[index];
                index++;
            }
        }

        for (auto str : vecBuilder) {
            res += str;
        }

        return res;
    }
};