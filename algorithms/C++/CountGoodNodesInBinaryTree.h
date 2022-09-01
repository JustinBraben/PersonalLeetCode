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

    int dfs(TreeNode* node, int maxVal) {

        // If empty node don't count
        if (!node)
            return 0;

        // check to see if the value at your current node
        // is higher than the highest allowed value
        // to consider counting node
        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);

        // Recursively preorder traverse left and right of tree
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);

        return res;

    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};