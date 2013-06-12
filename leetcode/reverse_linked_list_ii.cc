/* Copyright 2013 <ZhiQiang Fan>

   Reverse a linked list from position m to n. Do it in-place and in
   one-pass.

   For example:
   Given 1->2->3->4->5->NULL, m = 2 and n = 4,
   return 1->4->3->2->5->NULL.

   Note:
   Given m, n satisfy the following condition:
   1 <= m <= n <= length of list.
*/
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode * tag = NULL;
    ListNode * prev = NULL;
    ListNode * cur = NULL;
    ListNode * next = NULL;

    cur = head;
    while (true) {
      if (m == 1) {
        // for i.e, 1->2->3->4, m = 2, n = 3, first loop, cur = 2
        // next = 3;
        next = cur->next;
        while (n > 1) {
          // prev = 2
          prev = cur;
          // cur = 3
          cur = next;
          // next = 4
          next = next->next;
          // 1->2<->3xx4
          cur->next = prev;
          n--;
        }
        // reverse head
        if (!tag) {
          head->next = next;
          head = cur;
        } else {
          // 1->2<->3xx4
          tag->next->next = next;
          // 1->2->4, 3->2 ==> 1->3->2->4
          tag->next = cur;
        }
        break;
      }
      tag = cur;
      cur = cur->next;
      m--;
      n--;
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
  int a[] = {1};
  ListNode * head = create_list(a, sizeof(a)/sizeof(int));
  Solution s;
  int m, n;
  scanf("%d %d", &m, &n);
  head = s.reverseBetween(head, m, n);
  print_list(head);
  delete_list(head);
  return 0;
}
