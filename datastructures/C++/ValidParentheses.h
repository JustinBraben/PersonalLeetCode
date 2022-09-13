class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (const auto& c : s) {
            switch (c) {
            case '{': stk.push('}'); break;
            case '[': stk.push(']'); break;
            case '(': stk.push(')'); break;
                // Return false if s is an empty string
                // or if c is no longer the top of the stack
                // Otherwise remove the top of the stack
            default:
                if (stk.size() == 0 || c != stk.top())
                    return false;
                else
                    stk.pop();
            }
        }

        // If there were the same amount of corresponding brackets in
        // the correct order, the stack should be empty
        return stk.size() == 0;
    }
};