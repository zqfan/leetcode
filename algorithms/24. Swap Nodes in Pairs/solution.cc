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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        auto cur = & dummy;
        // if there are more than two nodes left
        while ( cur && cur->next && cur->next->next ) {
            // record the first of current pair and the first of next pair
            auto t1 = cur->next;
            auto t2 = cur->next->next->next;
            // swap
            cur->next = cur->next->next;
            cur->next->next = t1;
            // move to next pair
            t1->next = t2;
            cur = t1;
        }
        return dummy.next;
    }
};
