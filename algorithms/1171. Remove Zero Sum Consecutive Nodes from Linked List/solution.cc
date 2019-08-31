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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> sum2tail;
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        int sum = 0;
        while (cur) {
            sum += cur->val;
            if (sum2tail.count(sum)) {
                // key point 1: dead reference must be cleaned.
                // optimize point 1: because we have cleaned all dead reference before,
                // so every new sum is in the map. no need to check if the cached node
                // is a dead reference.
                // optimize point 2: using cur for inner loop instead of an additional pointer. 
                cur = sum2tail[sum]->next;
                int cursum = sum + cur->val;
                while (sum != cursum) {
                    sum2tail.erase(cursum);
                    cur = cur->next;
                    cursum += cur->val;
                    // need to free deleted node memory
                }
                sum2tail[sum]->next = cur->next;
            } else {
                sum2tail[sum] = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};
