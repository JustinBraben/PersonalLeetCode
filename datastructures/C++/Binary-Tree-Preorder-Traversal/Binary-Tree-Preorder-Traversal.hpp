/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        stack<TreeNode*> todo;

        // traverse tree so long as root is not null
        // or if the stack is not empty
        while (root || !todo.empty()) {

            // if the current root of the binary tree is not null
            if (root) {
                nodes.push_back(root->val);
                if (root->right) {
                    todo.push(root->right);
                }
                root = root->left;
            }
            else {
                root = todo.top();
                todo.pop();
            }
        }
        return nodes;
    }
};