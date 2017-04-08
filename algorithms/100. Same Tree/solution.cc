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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ( p && q ) {
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        return NULL == p && NULL == q;
    }
};

// 54 / 54 test cases passed.
// Status: Accepted
// Runtime: 0 ms
