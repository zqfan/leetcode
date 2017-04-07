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
    int getMinimumDifference(TreeNode* root) {
        TreeNode * pre = NULL;
        int minDiff = INT_MAX;
        dfs(root, pre, minDiff);
        return minDiff;
    }
    void dfs(TreeNode * root, TreeNode * & pre, int & minDiff) {
        if ( root ) {
            dfs(root->left, pre, minDiff);
            if ( pre ) {
                minDiff = min(minDiff, root->val - pre->val);
            }
            pre = root;
            dfs(root->right, pre, minDiff);
        }
    }
};
