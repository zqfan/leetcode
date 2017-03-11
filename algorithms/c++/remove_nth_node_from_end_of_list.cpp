/* Given a linked list, remove the nth node from the end of list and
   return its head.
   Note:
   Given n will always be valid.
   Try to do this in one pass. */
#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  // actually, i think two pass is the most efficient method
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode * tmp = head;
    ListNode * target_pre = NULL;
    while (tmp) {
      tmp = tmp->next;
      if (target_pre)
        target_pre = target_pre->next;
      if (n == 0)
        target_pre = head;
      n = n >= 0 ? n - 1 : -1;
    }
    if (target_pre) {
      tmp = target_pre->next;
      target_pre->next = target_pre->next->next;
      delete tmp;
    } else if (n == 0) { // want to remove the head
      tmp = head;
      head = head->next;
      delete tmp;
    }
    return head;
  }
};

// return 1->2->3->4->5 if n = 54321
ListNode * create_list(int n) {
    if (n < 0)
        return NULL;
    else if (n == 0)
        return new ListNode(0);
    ListNode * first = NULL;
    ListNode * cur = NULL;
    while (n != 0) {
        if (NULL != first) {
            cur->next = new ListNode(n % 10);
            cur = cur->next;
        } else
            cur = first = new ListNode(n % 10);
        n /= 10;
    }
    return first;
}

void delete_list(ListNode * l) {
    ListNode * tmp = NULL;
    while (NULL != l) {
        tmp = l;
        l = l->next;
        delete tmp;
    }
}

// return 54321 if l = 1->2->3->4->5
int get_number(ListNode * l) {
    int n = 0;
    int times = 1;
    while (NULL != l) {
        n += l->val * times;
        l = l->next;
        times *= 10;
    }
    return n;
}

int main() {
  // get 1->2->3->4->5 if n = 54321
  ListNode * root = create_list(54321);
  Solution sol;
  root = sol.removeNthFromEnd(root, 5);
  // print 54321 if list = 1->2->3->4->5
  cout << get_number(root) << endl;
  delete_list(root);
  return 0;
}
