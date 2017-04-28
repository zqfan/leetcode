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
    unordered_map<TreeNode *, int> mem;
public:
    int rob(TreeNode* root) {
        if ( ! root ) {
            return 0;
        }
        if ( mem.find(root) != mem.end() ) {
            return mem[root];
        }
        int withRoot = root->val;
        if ( root->left ) {
            withRoot += rob(root->left->left) + rob(root->left->right);
        }
        if ( root->right ) {
            withRoot += rob(root->right->left) + rob(root->right->right);
        }
        int withoutRoot = rob(root->left) + rob(root->right);
        return mem[root] = max(withRoot, withoutRoot);
    }
};

// 124 / 124 test cases passed.
// Status: Accepted
// Runtime: 13 ms, without mem it will cost 1359 ms instead
// beats 54.99 %
