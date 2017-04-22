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
        stack<TreeNode *> s;
        while ( root || s.size() > 0 ) {
            if ( root ) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                values.push_back(root->val);
                root = root->right;
            }
        }
        return values;
    }
};
