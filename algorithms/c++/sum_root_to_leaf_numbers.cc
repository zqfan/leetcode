/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree containing digits from 0-9 only, each
   root-to-leaf path could represent a number.
   An example is the root-to-leaf path 1->2->3 which represents the
   number 123.
   Find the total sum of all root-to-leaf numbers.
   For example,
    1
   / \
  2   3
   The root-to-leaf path 1->2 represents the number 12.
   The root-to-leaf path 1->3 represents the number 13.
   Return the sum = 12 + 13 = 25.
*/
#include <cstdio>
#include "binary_tree.h"

class Solution {
  public:
  void sum_numbers(TreeNode * root, int * sum, int ancestor) {
    if (!root)
      return;
    ancestor = ancestor * 10 + root->val;
    // leaf node
    if (!root->left && !root->right) {
      *sum = *sum + ancestor;
      return;
    }
    this->sum_numbers(root->left, sum, ancestor);
    this->sum_numbers(root->right, sum, ancestor);
  }

  int sumNumbers(TreeNode *root) {
    int sum = 0;

    if (!root)
      return 0;
    this->sum_numbers(root, &sum, 0);
    return sum;
  }
};

int main() {
  int n[] = {1, 2, '#'};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int));
  printf("%d\n", Solution().sumNumbers(root));
  delete_binary_tree(root);
  return 0;
}
