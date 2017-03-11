/*  Given a linked list, swap every two adjacent nodes and return its
    head.

    For example,
    Given 1->2->3->4, you should return the list as 2->1->4->3.

    Your algorithm should use only constant space. You may not modify
    the values in the list, only nodes itself can be changed. */
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
  ListNode *swapPairs(ListNode *head) {
    // if we want to swap a,b, prev is in front of a
    ListNode * prev = NULL;
    // odd is a
    ListNode * odd = NULL;
    // next is node after b
    ListNode * next = NULL;
    ListNode * cur = head;
    // let swap a,b,c,d,$
    // in comments, X means list broken, O means loop, $ means end
    while (cur && cur->next) {
      odd = cur;
      next = cur->next->next;
      if (!prev) { // cur == head
        head = head->next; // b,c,d,$
        head->next = odd; // b,a,O
        head->next->next = next; // b,a,c,d,$
      } else {
        prev->next = odd->next; // b,a,d,$
        prev->next->next = odd; // b,a,d,a,d,O
        odd->next = next; // b,a,d,a,$
      }
      prev = odd; // odd is swap to even position
      cur = next; // jump two nodes, which exactly is next node
    }
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
  int a[] = {1,2,3,4,5,6};
  vector<int> arr(a, a+sizeof(a)/sizeof(int));
  ListNode * head = create_list(arr);
  print_list(head);
  ListNode * r = sol.swapPairs(head);
  print_list(r);
  delete_list(r);
  return 0;
}
