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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightmost;
        dfs(root, 0, rightmost);
        return rightmost;
    }

    void dfs(TreeNode * root, int curHeight, vector<int> & rightmost) {
        if ( root ) {
            if ( curHeight == rightmost.size() ) {
                rightmost.push_back(root->val);
            }
            dfs(root->right, curHeight + 1, rightmost);
            dfs(root->left, curHeight + 1, rightmost);
        }
    }
};
