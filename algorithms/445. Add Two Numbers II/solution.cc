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
        int n1 = getLength(l1);
        int n2 = getLength(l2);
        ListNode * c1 = l1, * c2 = l2, * head = NULL, * tmp;
        while ( n1 > 0 && n2 > 0 ) {
            int sum = 0;
            if ( n1 >= n2 ) {
                sum += c1->val;
                c1 = c1->next;
                --n1;
            }
            if ( n2 > n1 ) {
                sum += c2->val;
                c2 = c2->next;
                --n2;
            }
            tmp = new ListNode(sum);
            tmp->next = head;
            head = tmp;
        }
        ListNode * cur = head, * pre;
        int carry = 0;
        while ( cur ) {
            carry = cur->val + carry;
            cur->val = carry % 10;
            pre = cur;
            cur = cur->next;
            carry /= 10;
        }
        if ( carry ) {
            cur = new ListNode(1);
            pre->next = cur;
        }
        return reverse(head);
    }

    int getLength(ListNode * head) {
        int length = 0;
        ListNode * cur = head;
        while ( cur ) {
            ++length;
            cur = cur->next;
        }
        return length;
    }

    ListNode * reverse(ListNode * head) {
        ListNode * cur = head, * pre = NULL, * tmp;
        while ( cur ) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
