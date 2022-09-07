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
    string tree2str(TreeNode* root) {

        if (!root) return "";

        string res = to_string(root->val);

        if (root->left) // check left side
            res += "(" + tree2str(root->left) + ")";
        if (root->right) { // check right side
            if (!root->left) res += "()"; //left side not present, but right side present
            res += "(" + tree2str(root->right) + ")";
        }
        return res;
    }
};