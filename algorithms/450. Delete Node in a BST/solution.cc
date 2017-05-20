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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( ! root ) {
            return root;
        }
        if ( root->val == key ) {
            if ( ! root->left ) {
                root = root->right;
            } else if ( ! root->left->right ) {
                root->left->right = root->right;
                root = root->left;
            } else {
                auto cur = root->left;
                while ( cur && cur->right && cur->right->right ) {
                    cur = cur->right;
                }
                auto newRoot = cur->right;
                cur->right = cur->right->left;
                newRoot->left = root->left;
                newRoot->right = root->right;
                root = newRoot;
            }
        } else if ( root->val > key ) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
