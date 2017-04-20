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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> count;
        dfs(root, count);
        int m = 0;
        for ( auto & p : count ) {
            m = max(m, p.second);
        }
        vector<int> result;
        for ( auto & p : count ) {
            if ( p.second == m ) {
                result.push_back(p.first);
            }
        }
        return result;
    }

    int dfs(TreeNode * root, map<int, int> & count) {
        if ( ! root ) {
            return 0;
        }
        int sum = dfs(root->left, count) + dfs(root->right, count) + root->val;
        ++count[sum];
        return sum;
    }
};
