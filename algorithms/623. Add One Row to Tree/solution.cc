/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        // based on @alexander
        if ( d < 2 ) {
            auto node = new TreeNode(v);
            node->left = d ? root : nullptr;
            node->right = d ? nullptr : root;
            return node;
        } else if ( root ) {
            root->left = addOneRow(root->left, v, d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right, v, d > 2 ? d - 1 : 0);
        }
        return root;
    }
};
