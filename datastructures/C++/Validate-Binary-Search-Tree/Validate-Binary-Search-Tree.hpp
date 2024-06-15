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
    bool isValidBST(TreeNode* root) {

        TreeNode* prev = NULL;
        return validate(root, prev);

    }

    bool validate(TreeNode* node, TreeNode*& prev) {
        // If a null is found you reached an end of the binary tree
        if (node == NULL) return true;

        // If validating on the left node ever returned false
        // keep cascading false
        if (!validate(node->left, prev)) return false;

        // Sanity check prev node isn't null (first time prev is passed will be null)
        // and make sure prev val is always >= current node val
        // otherwise return false;
        if (prev != NULL && prev->val >= node->val) return false;

        // set prev to the current node
        prev = node;

        // Recursively call validate travelling down the right node, and passing along
        // a ref to the last used node
        return validate(node->right, prev);
    }

};