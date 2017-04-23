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
    int findTilt(TreeNode* root) {
        int diff = 0;
        dfs(root, diff);
        return diff;
    }

    int dfs(TreeNode * root, int & diff) {
        if ( NULL == root ) {
            return 0;
        }
        int left = dfs(root->left, diff);
        int right = dfs(root->right, diff);
        diff += abs(left - right);
        return left + root->val + right;
    }
};
