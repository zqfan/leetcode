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
    bool isPalindrome(ListNode* head) {
        // @StefanPochmann
        ListNode * reverse = NULL, * fast = head, *tmp;
        while ( fast && fast->next ) {
            fast = fast->next->next;
            tmp = head->next;
            head->next = reverse;
            reverse = head;
            head = tmp;
        }
        fast = fast ? head->next : head;
        bool p = true;
        while ( reverse ) {
            p = p && reverse->val == fast->val;
            fast = fast->next;
            tmp = reverse->next;
            reverse->next = head;
            head = reverse;
            reverse = tmp;
        }
        return p;
    }
};
