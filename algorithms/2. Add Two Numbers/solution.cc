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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dummy(0), * cur = & dummy;
        while ( l1 || l2 || carry ) {
            carry += l1 ? l1->val : 0;
            carry += l2 ? l2->val : 0;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            cur->next = new ListNode(carry % 10);
            cur = cur->next;
            carry /= 10;
        }
        return dummy.next;
    }
};
