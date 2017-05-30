/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode * cur = head;
        while ( cur ) {
            ++count;
            cur = cur->next;
        }
        cur = head;
        return inorder(count, cur);
    }

    TreeNode * inorder(int count, ListNode * & cur) {
        if ( 0 == count ) return NULL;
        TreeNode * root = new TreeNode(0);
        root->left = inorder(count / 2, cur);
        root->val = cur->val;
        cur = cur->next;
        root->right = inorder(count - count / 2 - 1, cur);
        return root;
    }
};
