/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, find the maximum path sum.
   The path may start and end at any node in the tree.
   For example:
   Given the below binary tree,
       1
      / \
     2   3
     Return 6.
*/
#include <cstdio>
#include <algorithm>
#include "binary_tree.h"

class Solution {
  public:
  // return max path sum from root to any of its child
  // across_child_max means max path sum from any node to any node
  // so it may across two child
  int path_sum(TreeNode * root, int * across_child_max) {
    if (!root)
      return 0;
    // leaf node
    if (!root->left && !root->right) {
      if (root->val > *across_child_max)
        *across_child_max = root->val;
      return root->val;
    }
    int left, right, sum, child_max;
    left = this->path_sum(root->left, across_child_max);
    right = this->path_sum(root->right, across_child_max);
    sum = root->val;
    if (left > 0)
      sum += left;
    if (right > 0)
      sum += right;
    if (sum > *across_child_max)
      *across_child_max = sum;
    child_max = std::max(left, right);
    if (child_max > 0)
      return root->val + child_max;
    else
      return root->val;
  }

  int maxPathSum(TreeNode *root) {
    if (!root)
      return 0;
    int across_child_max = root->val;
    int max_sum = this->path_sum(root, &across_child_max);
    return std::max(max_sum, across_child_max);
  }
};

int main() {
  int a[] = {-1, 2, 3, 5, '#'};
  TreeNode * root = create_binary_tree(a, sizeof(a)/sizeof(int));
  printf("%d\n", Solution().maxPathSum(root));
  delete_binary_tree(root);
  return 0;
}
