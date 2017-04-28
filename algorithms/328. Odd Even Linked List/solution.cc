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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddhead(0), evenhead(0);
        ListNode * oddcur = & oddhead, * evencur = & evenhead;
        for ( int i = 1; head; ++i, head = head->next ) {
            if ( i & 1 ) {
                oddcur->next = head;
                oddcur = head;
            } else {
                evencur->next = head;
                evencur = head;
            }
        }
        oddcur->next = evenhead.next;
        evencur->next = NULL;
        return oddhead.next;
    }
};
