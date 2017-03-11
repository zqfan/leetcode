/*
Copyright 2013 ZhiQiang Fan <aji.zqfan@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Given a singly linked list where elements are sorted in ascending
order, convert it to a height balanced BST.
*/
#include "linked_list.h"
#include "binary_tree.h"

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    // find the length of list, left part to generate left child tree
    int len = 0;
    ListNode * cur = head;

    if (!head)
      return NULL;
    // get the len
    while (cur) {
      len++;
      cur = cur->next;
    }
    return _sorted_list_to_bst(head, len);
  }

  TreeNode * _sorted_list_to_bst(ListNode * head, int len) {
    int mid = 0;
    ListNode * cur = head;
    TreeNode * root = NULL;

    if (!head || len < 1)
      return NULL;
    // get the middle
    while (mid < len/2) {
      cur = cur->next;
      mid++;
    }
    root = new TreeNode(cur->val);
    root->left = _sorted_list_to_bst(head, mid);
    root->right = _sorted_list_to_bst(cur->next, len - mid - 1);
    return root;
  }
};

int main() {
  int a[] = {1, 2, 3, 4, 5, 6};
  ListNode * head = create_list(a, sizeof(a)/sizeof(int));
  Solution s;
  TreeNode * root = s.sortedListToBST(head);
  print_binary_tree_inorder(root);
  delete_list(head);
  delete_binary_tree(root);
  return 0;
}
