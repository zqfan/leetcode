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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        while ( root ) {
            if ( NULL == root->left ) {
                values.push_back(root->val);
                root = root->right;
            } else {
                auto rightmost = root->left;
                while ( rightmost->right && rightmost->right != root ) {
                    rightmost = rightmost->right;
                }
                if ( rightmost->right == root ) {
                    rightmost->right = NULL;
                    root = root->right;
                } else {
                    values.push_back(root->val);
                    rightmost->right = root;
                    root = root->left;
                }
            }
        }
        return values;
    }
};
