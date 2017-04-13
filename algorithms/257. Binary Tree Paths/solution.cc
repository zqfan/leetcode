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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return paths;
    }

    void dfs(TreeNode * root, string p, vector<string> & paths) {
        if ( NULL == root ) {
            return;
        }
        if ( NULL == root->left && NULL == root->right ) {
            paths.push_back(p + to_string(root->val));
        }
        p = p + to_string(root->val) + "->";
        dfs(root->left, p, paths);
        dfs(root->right, p, paths);
    }
};
