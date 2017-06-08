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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head, start = head;
        while ( fast && fast->next ) {
            fast = fast->next->next;
            slow = slow->next;
            if ( slow == fast ) {
                while ( start != slow ) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
        return NULL;
    }
};
