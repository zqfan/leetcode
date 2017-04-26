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
        stack<TreeNode *> s;
        s.push(root);
        while ( ! s.empty() ) {
            root = s.top();
            s.pop();
            if ( root ) {
                values.push_back(root->val);
                s.push(root->right);
                s.push(root->left);
            }
        }
        return values;
    }
};
