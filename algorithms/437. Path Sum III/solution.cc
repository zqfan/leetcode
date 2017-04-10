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
    int pathSum(TreeNode* root, int sum) {
        if ( NULL == root ) {
            return 0;
        }
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        return rootSum(root, sum) + left + right;
    }
    
    int rootSum(TreeNode * root, int sum) {
        if ( NULL == root ) {
            return 0;
        }
        int left = rootSum(root->left, sum - root->val);
        int right = rootSum(root->right, sum - root->val);
        return int(sum == root->val) + left + right;
    }
};
