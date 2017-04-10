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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ( (root->val - p->val) * (root->val - q->val) > 0 ) {
            if ( root->val > p-> val ) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};
