/* Copyright 2013 <ZhiQiang Fan>

   Given a linked list and a value x, partition it such that all nodes
   less than x come before nodes greater than or equal to x.

   You should preserve the original relative order of the nodes in
   each of the two partitions.

   For example,
   Given 1->4->3->2->5->2 and x = 3,
   return 1->2->2->4->3->5.
*/
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  ListNode *partition(ListNode *head, int x) {
    ListNode * last_less = NULL;  // last node less than x
    ListNode * cur = NULL;
    ListNode * prev = NULL;

    cur = head;
    while (cur && cur->val < x) {
      prev = cur;
      cur = cur->next;
    }
    last_less = prev;
    while (cur) {
      if (cur->val < x) {
        prev->next = cur->next;
        if (!last_less) {
          cur->next = head;
          head = cur;
        } else {
          cur->next = last_less->next;
          last_less->next = cur;
        }
        last_less = cur;
        cur = prev->next;
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
  int a[] = {1, 4, 3, 2, 5, 2};
  int x;
  scanf("%d", &x);
  Solution s;
  ListNode * head = create_list(a, sizeof(a)/sizeof(int));
  print_list(head);
  head = s.partition(head, x);
  print_list(head);
  delete_list(head);
  return 0;
}
