/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode * head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int result;
        int count = 1;
        for ( ListNode * cur = head; cur != NULL; cur = cur->next ) {
            // rand() returns 0...RAND_MAX which depends on compiler,
            // it might be 0x7fff in some outdated cases,
            // and it is 0x7fffffff in leetcode.
            if ( rand() % count == 0 ) {
                result = cur->val;
            }
            count += 1;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
