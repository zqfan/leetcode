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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return rm(head, n).second;
    }

    pair<int, ListNode *> rm(ListNode * node, int target) {
        if ( ! node ) {
            return make_pair(0, (ListNode *)NULL);
        }
        pair<int, ListNode *> p = rm(node->next, target);
        node->next = p.second;
        if ( target == p.first + 1 ) {
            return make_pair(p.first + 1, node->next);
        } else {
            return make_pair(p.first + 1, node);
        }
    }
};

// 207 / 207 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 59.80 %
