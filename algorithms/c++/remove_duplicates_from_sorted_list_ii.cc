/* Copyright 2013 <ZhiQiang Fan>

   Given a sorted linked list, delete all nodes that have duplicate
   numbers, leaving only distinct numbers from the original list.

   For example,
   Given 1->2->3->3->4->4->5, return 1->2->5.
   Given 1->1->1->2->3, return 2->3.
*/
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode * prev = NULL;
    bool distinct = true;
    ListNode * cur = NULL;
    ListNode * tmp = NULL;

    cur = head;
    while (cur) {
      if (cur->next && cur->next->val == cur->val) {
        tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = NULL;
        distinct = false;
        continue;
      }
      if (!distinct) {
        // remove head
        if (!prev) {
          head = cur->next;
        } else {
          prev->next = cur->next;
        }
        tmp = cur;
        cur = cur->next;
        delete tmp;
        distinct = true;
        continue;
      }
      prev = cur;
      cur = cur->next;
    }

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
  ListNode * head = create_list(a, sizeof(a)/sizeof(int));
  Solution s;
  head = s.deleteDuplicates(head);
  print_list(head);
  delete_list(head);
  return 0;
}
