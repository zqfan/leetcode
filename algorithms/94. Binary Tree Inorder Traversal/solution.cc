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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> values;
        while ( root ) {
            if ( root->left ) {
                auto rightmost = root->left;
                while ( rightmost->right && rightmost->right != root ) {
                    rightmost = rightmost->right;
                }
                if ( NULL == rightmost->right ) {
                    rightmost->right = root;
                    root = root->left;
                } else {
                    rightmost->right = NULL;
                    values.push_back(root->val);
                    root = root->right;
                }
            } else {
                values.push_back(root->val);
                root = root->right;
            }
        }
        return values;
    }
};
