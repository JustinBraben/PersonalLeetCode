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
    int maxDepth(TreeNode* root) {

        if (!root) return 0;

        int maxDepth = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            ++maxDepth;

            for (int i = 0, n = q.size(); i < n; ++i) {

                TreeNode* p = q.front();
                q.pop();

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);

            }
        }

        return maxDepth;
    }
};