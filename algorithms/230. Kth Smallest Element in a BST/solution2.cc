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
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        dfs(root, k, result);
        return result;
    }

    void dfs(TreeNode * root, int & k, int & result) {
        if ( root && k > 0 ) {
            dfs(root->left, k, result);
            if ( --k == 0 ) {
                result = root->val;
            }
            dfs(root->right, k, result);
        }
    }
};

// 91 / 91 test cases passed.
// Status: Accepted
// Runtime: 26 ms
// beats 3.50 %
