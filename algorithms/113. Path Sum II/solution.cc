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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, sum, path, result);
        return result;
    }

    void dfs(TreeNode * root, int target, vector<int> & path, vector<vector<int>> & result) {
        if ( ! root ) return;
        path.push_back(root->val);
        if ( ! root->left && ! root->right && root->val == target) result.push_back(path);
        dfs(root->left, target - root->val, path, result);
        dfs(root->right, target - root->val, path, result);
        path.pop_back();
    }
};
