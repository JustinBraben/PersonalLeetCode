class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Create a stack to store characters in the desired order.
        stack<char> st;

        // Create two arrays to keep track of the last index of each character in 's' and whether a character has been seen.
        vector<int> lastindex(26, 0); // Initialize with 0 for all characters.
        vector<bool> seen(26, false);  // Initialize as unseen for all characters.

        // First loop to populate the 'lastindex' array with the last index of each character in 's'.
        for (int i = 0; i < s.size(); i++) {
            lastindex[s[i] - 'a'] = i;  // Convert character to an index in the range 0-25 and store the last index.
        }

        // Second loop to build the result string while eliminating duplicate characters.
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';  // Convert the current character to an index.

            // If the current character has already been seen, skip it.
            if (seen[curr]) {
                continue;
            }

            // Check if there are characters in the stack that can be removed to maintain the lexicographical order.
            while (!st.empty() && st.top() > s[i] && i < lastindex[st.top() - 'a']) {
                seen[st.top() - 'a'] = false;  // Mark the character as unseen.
                st.pop();  // Remove the character from the stack.
            }

            // Push the current character onto the stack and mark it as seen.
            st.push(s[i]);
            seen[curr] = true;
        }

        // Construct the result string by popping characters from the stack.
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        // Reverse the result string to get the correct order.
        reverse(res.begin(), res.end());
        return res;
    }
};
