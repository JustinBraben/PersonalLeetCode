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
    TreeNode* invertTree(TreeNode* root) {

        if (!root)
            return root;

        queue<TreeNode*> q;     // our queue to do BFS
        q.push(root);           // push very first item - root

        while (!q.empty()) {      // run until there are nodes in the queue 

            TreeNode* node = q.front();

            if (node) {
                q.push(node->left);
                q.push(node->right);
                swap(node->left, node->right);
            }

            q.pop();

        }

        return root;
    }
};