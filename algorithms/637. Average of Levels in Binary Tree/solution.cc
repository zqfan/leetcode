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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum, count;
        dfs(root, 1, sum, count);
        for ( int i = 0; i < sum.size(); ++i )
            sum[i] /= count[i];
        return sum;
    }

    void dfs(TreeNode * root, int height, vector<double> & sum, vector<double> & count) {
        if ( root ) {
            if ( height > sum.size() ) {
                sum.push_back(0);
                count.push_back(0);
            }
            sum[height-1] += root->val;
            ++count[height-1];
            dfs(root->left, height + 1, sum, count);
            dfs(root->right, height + 1, sum, count);
        }
    }
};

// 63 / 63 test cases passed.
// Status: Accepted
// Runtime: 13 ms
