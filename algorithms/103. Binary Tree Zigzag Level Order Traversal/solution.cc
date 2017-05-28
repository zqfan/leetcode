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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if ( ! root ) return {};
        vector<vector<int>> res;
        queue<TreeNode *> cur({root});
        vector<int> tmp;
        int zigzag = 0;
        while ( cur.size() ) {
            tmp.clear();
            for ( int n = cur.size(), i = 0; i < n; ++i ) {
                auto node = cur.front();
                cur.pop();
                if ( node->left ) cur.push(node->left);
                if ( node->right ) cur.push(node->right);
                tmp.push_back(node->val);
            }
            if ( zigzag ) reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            zigzag ^= 1;
        }
        return res;
    }
};
