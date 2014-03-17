/*  Given a linked list, reverse the nodes of a linked list k at a
    time and return its modified list.

    If the number of nodes is not a multiple of k then left-out nodes
    in the end should remain as it is.

    You may not alter the values in the nodes, only nodes itself may
    be changed.

    Only constant memory is allowed. */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  // list should not have circle
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode * cur = NULL;
    ListNode * cur_next = NULL;
    ListNode * tag = NULL;
    ListNode * reverse_cur = NULL;
    ListNode * reverse_cur_next = NULL;
    ListNode * prev = NULL;
    int n;

    if (k <= 1)
      return head;

    cur = head;
    n = k;
    while (cur) {
      if (n == k)
        tag = cur;
      n--;
      // save cur->next because it may be changed when reverse
      cur_next = cur->next;
      if (0 == n) {
        // first reverse group need to change the head
        if (!prev) {
          head = cur;
        }
        // reverse the k nodes
        n = k;
        // let the prev group last one point to current group last
        if (prev)
          prev->next = cur;
        // let the next group first one to be current group first
        // one's next one
        prev = cur->next;
        // start to reverse n nodes
        reverse_cur = tag;
        while (--n >= 0) {
          // save the next node to avoid lost
          reverse_cur_next = reverse_cur->next;
          reverse_cur->next = prev;
          prev = reverse_cur;
          reverse_cur = reverse_cur_next;
        }
        // indicate new round
        n = k;
        // let the current first one to be next group's prev
        prev = tag;
      } // end if 0 == n
      cur = cur_next;
    } // end while
    return head;
  }
};

ListNode * create_list(vector<int> arr) {
  ListNode * head = NULL;
  ListNode * cur = NULL;

  if (arr.size() < 1)
    return NULL;
  cur = head = new ListNode(arr[0]);
  for (int i = 1; i < arr.size(); i++) {
    cur->next = new ListNode(arr[i]);
    cur = cur->next;
  }
  return head;
}

void delete_list(ListNode * l) {
    ListNode * cur = NULL;
    while (l) {
        cur = l;
        l = l->next;
        delete cur;
    }
}

void print_list(ListNode * l) {
  ListNode * cur = l;
  while (cur) {
    cout << cur->val << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Solution sol;
  int a[] = {1,2,3,4,5,6,7,8,9};
  vector<int> arr(a, a+sizeof(a)/sizeof(int));
  ListNode * head = create_list(arr);
  head = sol.reverseKGroup(head, 3);
  print_list(head);
  delete_list(head);
  return 0;
}
