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
    int maxHeight = 0;
    int bottomLeft = 0;
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return bottomLeft;
    }

    void dfs(TreeNode * root, int height) {
        if ( root ) {
            if ( height + 1 > maxHeight ) {
                maxHeight = height + 1;
                bottomLeft = root->val;
            }
            dfs(root->left, height + 1);
            dfs(root->right, height + 1);
        }
    }
};
