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
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }

    pair<int, int> dfs(TreeNode * root) {
        if ( ! root ) {
            return make_pair(0, 0);
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int withRoot = root->val + left.second + right.second;
        int withoutRoot = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(withRoot, withoutRoot);
    }
};

// 124 / 124 test cases passed.
// Status: Accepted
// Runtime: 9 ms
// beats 71.74 %
