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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode *> q;
        q.push_back(root);
        for ( int i = 0; i < q.size(); ++i ) {
            if ( q[i]->right ) {
                q.push_back(q[i]->right);
            }
            if ( q[i]->left ) {
                q.push_back(q[i]->left);
            }
        }
        return q.back()->val;
    }
};
