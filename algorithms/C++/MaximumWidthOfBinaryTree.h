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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        int maxWidth = 1;
        queue<pair<TreeNode*, int>> treeQ;
        treeQ.push({ root, 0 });

        while (!treeQ.empty()) {
            int levelSize = treeQ.size();
            int startIndex = treeQ.front().second;
            int endIndex = treeQ.back().second;
            maxWidth = max(maxWidth, endIndex - startIndex + 1);

            for (int i = 0; i < levelSize; i++) {
                auto nodeIndexPair = treeQ.front();
                auto node = nodeIndexPair.first;
                int nodeIndex = nodeIndexPair.second - startIndex;
                treeQ.pop();

                if (node->left != nullptr) {
                    treeQ.push({ node->left, 2LL * nodeIndex + 1 });
                }

                if (node->right != nullptr) {
                    treeQ.push({ node->right, 2LL * nodeIndex + 2 });
                }
            }
        }

        return maxWidth;
    }
};