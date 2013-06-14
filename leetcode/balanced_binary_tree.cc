/* Given a binary tree, determine if it is height-balanced.

   For this problem, a height-balanced binary tree is defined as a
   binary in which the depth of the two subtrees of every node never
   differ by more than 1.
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include "binary_tree.h"
using std::vector;
using std::queue;

class Solution {
  public:
  int depth_with_balance_check(TreeNode * root) {
    int left_dep, right_dep;
    if (!root)
      return 0;
    left_dep = this->depth_with_balance_check(root->left);
    right_dep = this->depth_with_balance_check(root->right);
    // if child is not balanced, root is not balanced
    if (left_dep == -1 || right_dep == -1)
      return -1;
    // if child depth differ by more than 1, root is not balanced
    else if (std::abs(left_dep - right_dep) > 1)
      return -1;
    // it is balanced, and return its height
    else
      return std::max(left_dep, right_dep) + 1;
  }

  bool isBalanced(TreeNode *root) {
    return this->depth_with_balance_check(root) != -1;
  }
};

int main() {
  int n[] = {};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int), '#');
  Solution s;
  print_binary_tree_inorder(root);
  printf("%d\n", s.isBalanced(root));
  delete_binary_tree(root);
  return 0;
}
