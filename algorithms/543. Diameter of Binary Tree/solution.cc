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
    int diameter = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }

    int dfs(TreeNode * root) {
        if ( NULL == root ) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        diameter = max(diameter, left + right);
        return max(left, right) + 1;
    }
};

// 106 / 106 test cases passed.
// Status: Accepted
// Runtime: 12 ms
