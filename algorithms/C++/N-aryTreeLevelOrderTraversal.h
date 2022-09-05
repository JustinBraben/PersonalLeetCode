/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<Node*> nodeQ;
        nodeQ.push(root);

        while (!nodeQ.empty()) {

            int size = nodeQ.size();
            vector<int> currLevel;

            for (int i = 0; i < size; ++i) {
                Node* temp = nodeQ.front();
                nodeQ.pop();
                currLevel.push_back(temp->val);

                for (auto currNode : temp->children)
                    nodeQ.push(currNode);

            }
            res.push_back(currLevel);
        }
        return res;
    }
};