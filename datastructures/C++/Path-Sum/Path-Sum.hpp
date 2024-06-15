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
    bool hasPathSum(TreeNode* root, int targetSum) {

        // exit if the binary tree is empty
        if (root == NULL)
            return false;

        // Recursion will keep calling hasPathSum until a leaf is reached
        // once a leaf is reached it will see if the altered targetSum is equal to the targetSum
        if (root->val == targetSum && root->left == NULL && root->right == NULL)
            return true;

        // If True is ever found it will return true, otherwise the targetSum was never found
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};