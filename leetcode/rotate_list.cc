/* Copyright 2013 <ZhiQiang Fan>

   Given a list, rotate the list to the right by k places, where k is
   non-negative.

   For example:
   Given 1->2->3->4->5->NULL and k = 2,
   return 4->5->1->2->3->NULL.
*/
#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  ListNode *rotateRight(ListNode *head, int k) {
    // if k is less than O(T), it can be done in one scan
    // this is proved in ctci
    // here k has no such restriction, so i use two rounds scan
    // NOTE(zqfan): head and the list will be modified.
    int len = 0;
    ListNode * cur = head;
    // 1, 2, 3, 4, 5, and k = 2, tar_pre is point to 3
    ListNode * tar_pre = NULL, * tail = NULL, * tmp;

    if (!head)
      return head;
    // get the length of list, and the tail
    while (cur) {
      len++;
      tail = cur;
      cur = cur->next;
    }

    // check k
    k = k % len;
    if (k == 0)
      return head;

    // find the tar_pre node
    cur = tar_pre = head;
    while (len-- > k) {
      tar_pre = cur;
      cur = cur->next;
    }
    // rotate the nodes
    tmp = tar_pre->next;
    tar_pre->next = NULL;
    tail->next = head;
    head = tmp;

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
  ListNode * root = create_list(a, sizeof(a)/sizeof(int));
  Solution s;
  root = s.rotateRight(root, 0);
  print_list(root);
  delete_list(root);
  return 0;
}
