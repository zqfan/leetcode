/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if ( root ) {
            connect(root->left);
            connect(root->right);
            auto rightmost = root->left, leftmost = root->right;
            while ( rightmost ) {
                rightmost->next = leftmost;
                rightmost = rightmost->right;
                leftmost = leftmost->left;
            }
        }
    }
};
