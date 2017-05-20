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
    int sumNumbers(TreeNode* root) {
        int s = 0;
        dfs(root, 0, s);
        return s;
    }

    void dfs(TreeNode * root, int n, int & s) {
        if ( root ) {
            n = n * 10 + root->val;
            if ( ! root->left && ! root->right ) {
                s += n;
            }
            dfs(root->left, n, s);
            dfs(root->right, n, s);
        }
    }
};
