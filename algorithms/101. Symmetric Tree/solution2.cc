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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> left({root});
        queue<TreeNode *> right({root});
        TreeNode * p, * q;
        while ( left.size() > 0 && right.size() > 0 ) {
            p = left.front();
            q = right.front();
            if ( p && q ) {
                if ( p->val != q->val ) {
                    return false;
                }
                left.push(p->left);
                left.push(p->right);
                right.push(q->right);
                right.push(q->left);
            } else if ( p or q ) {
                return false;
            }
            left.pop();
            right.pop();
        }
        return true;
    }
};
