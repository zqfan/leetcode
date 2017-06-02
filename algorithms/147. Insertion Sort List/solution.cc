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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        dummy.next = head;
        ListNode * cur = head, * tmp;
        while ( cur && cur->next ) {
            if ( cur->val > cur->next->val ) {
                head = & dummy;
                while ( head->next->val <= cur->next->val ) {
                    head = head->next;
                }
                tmp = head->next;
                head->next = cur->next;
                cur->next = cur->next->next;
                head->next->next = tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
