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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;

        int hLeft = 0, hRight = 0;

        TreeNode* lNode = root, * rNode = root;

        while (lNode) {
            hLeft++;
            lNode = lNode->left;
        }

        while (rNode) {
            hRight++;
            rNode = rNode->right;
        }

        if (hLeft == hRight)
            return pow(2, hLeft) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};