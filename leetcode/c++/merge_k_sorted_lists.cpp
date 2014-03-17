/* Merge k sorted linked lists and return it as one sorted list.
   Analyze and describe its complexity. */
/* let T = sum(|L1| + |L2|+ ... + |Ln|), the brute force cost O(T*N),
   however, we can use a min-heap(n), so the cost is reduced to
   O(T*logN). C++ STL support max heap, currently, i don't know if
   there is any min heap or i should maintain it myself. */
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode * root = NULL;
    ListNode * cur = NULL;
    int min_val, min_index, i;
    while (true) {
      min_index = -1;
      for (i = 0; i < lists.size(); i++) {
        if (lists[i] && -1 == min_index) {
          min_val = lists[i]->val;
          min_index = i;
        } else if (lists[i] && lists[i]->val < min_val) {
          min_val = lists[i]->val;
          min_index = i;
        }
      }
      if (-1 == min_index)
        break;
      if (NULL == root)
        cur = root = lists[min_index];
      else {
        cur->next = lists[min_index];
        cur = cur->next;
      }
      lists[min_index] = lists[min_index]->next;
      cur->next = NULL;
    }
    return root;
  }
};

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
  // 1->3->5->7
  ListNode * l1 = create_list(7531);
  // 2->4->6->8
  ListNode * l2 = create_list(8642);
  vector<ListNode *> lists;
  lists.push_back(l1);
  lists.push_back(l2);
  Solution sol;
  ListNode * r = sol.mergeKLists(lists);
  // expect 87654321
  cout << get_number(r) << endl;
  delete_list(r);
  return 0;
}
