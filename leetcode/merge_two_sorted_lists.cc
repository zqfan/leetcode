/* Copyright 2013 <ZhiQiang Fan>

   Merge two sorted linked lists and return it as a new list. The new
   list should be made by splicing together the nodes of the first two
   lists.
*/
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode * head = new ListNode(0);
    ListNode * cur = head;

    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1)  // l1 has some elements left
      cur->next = l1;
    if (l2)  // l2 has some elements left
      cur->next = l2;

    cur = head;
    head = head->next;
    delete cur;

    return head;
  }
};

ListNode * create_list(int arr[], int n) {
  ListNode * head = NULL;
  ListNode * cur = NULL;

  if (n < 1)
    return NULL;
  cur = head = new ListNode(arr[0]);
  for (int i = 1; i < n; i++) {
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
    printf("%d ", cur->val);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  int a[] = {};
  int b[] = {1};
  ListNode * pa = create_list(a, sizeof(a)/sizeof(int));
  ListNode * pb = create_list(b, sizeof(b)/sizeof(int));
  Solution s;
  ListNode * r = s.mergeTwoLists(pa, pb);
  print_list(r);
  delete_list(r);
  return 0;
}
