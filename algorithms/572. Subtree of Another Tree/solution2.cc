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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ( isSameTree(s, t) ) return true;
        if ( NULL == s ) return false;
        return isSubtree(s->left, t) or isSubtree(s->right, t);
    }

    bool isSameTree(TreeNode * s, TreeNode * t) {
        if ( NULL == s and NULL == t ) return true;
        if ( NULL == s or NULL == t ) return false;
        if ( s->val != t->val ) return false;
        return isSameTree(s->left, t->left) and isSameTree(s->right, t->right);
    }
};

// 174 / 174 test cases passed.
// Status: Accepted
// Runtime: 25 ms
