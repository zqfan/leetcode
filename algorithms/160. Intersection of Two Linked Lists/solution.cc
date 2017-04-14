/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( NULL == headA || NULL == headB ) {
            return NULL;
        }
        auto pa = headA, pb = headB;
        while ( pa != pb ) {
            pa = pa ? pa->next : headB;
            pb = pb ? pb->next : headA;
        }
        return pa;
    }
};
