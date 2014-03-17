/* You are given two linked lists representing two non-negative
   numbers. The digits are stored in reverse order and each of their
   nodes contain a single digit. Add the two numbers and return it as
   a linked list. */
#include "iostream"
#include "cassert"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /* NOTE(zqfan): you should delete all the node after use to avoid leak */
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1 && NULL == l2)
            return NULL;
        ListNode * first = NULL;
        ListNode * cur = NULL;
        int a, b, det = 0;
        while (true) {
            if (NULL == l1 && NULL == l2) {
                if (det == 1)
                    cur->next = new ListNode(1);
                break;
            }
            a = NULL == l1 ? 0 : l1->val;
            b = NULL == l2 ? 0 : l2->val;
            if (NULL != first) {
                cur->next = new ListNode((a + b + det) % 10);
                cur = cur->next;
            } else
                cur = first = new ListNode((a + b + det) % 10);
            det = (a + b + det) / 10;
            l1 = NULL == l1 ? NULL : l1->next;
            l2 = NULL == l2 ? NULL : l2->next;
        }
        return first;
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
    int a1, a2;
    cin >> a1 >> a2;
    ListNode * l1 = create_list(a1);
    ListNode * l2 = create_list(a2);
    Solution s;
    ListNode * l = s.addTwoNumbers(l1, l2);
    int a = get_number(l);
    delete_list(l1);
    delete_list(l2);
    delete_list(l);
    cout << a << endl;
    assert(a == a1 + a2);
    return 0;
}
