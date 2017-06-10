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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        auto pre = & dummy;
        for ( int i = 1; i < m; ++i )
            pre = pre->next;
        ListNode * rhead = pre->next, * rtail;
        for ( int i = 0; i < n - m; ++i ) {
            rtail = rhead->next;
            rhead->next = rtail->next;
            rtail->next = pre->next;
            pre->next = rtail;
        }
        return dummy.next;
    }
};
