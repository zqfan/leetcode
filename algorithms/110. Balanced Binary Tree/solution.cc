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
    bool balanced = true;
public:
    bool isBalanced(TreeNode* root) {
        getDepth(root);
        return balanced;
    }

    int getDepth(TreeNode * root) {
        if ( NULL == root ) {
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if ( abs(left - right) > 1 ) {
            balanced = false;
        }
        return max(left, right) + 1;
    }
};
