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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }

    void dfs(TreeNode * root, int height, vector<vector<int>> & result) {
        if ( root ) {
            if ( height == result.size() ) {
                result.push_back(vector<int>());
            }
            result[height].push_back(root->val);
            dfs(root->left, height + 1, result);
            dfs(root->right, height + 1, result);
        }
    }
};
