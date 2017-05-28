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
        TreeLinkNode dummy(0);
        auto tail = & dummy;
        while ( root ) {
            tail->next = root->left;
            if ( tail->next ) tail = tail->next;
            tail->next = root->right;
            if ( tail->next ) tail = tail->next;
            root = root->next;
            if ( ! root ) {
                root = dummy.next;
                tail = & dummy;
            }
        }
    }
};
