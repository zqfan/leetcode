/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, check whether it is a mirror of itself (ie,
   symmetric around its center).

   For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
   But the following is not:

    1
   / \
  2   2
   \   \
   3    3
   Note:
   Bonus points if you could solve it both recursively and iteratively.
*/
#include <cstdio>
#include <vector>
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
  bool isSymmetric(TreeNode *root) {
    // There is no way to recursive, because single parameter cannot
    // hold enough info, but if we could write another routine, then
    // it is easy: check r1, r2, r1->left == r2->right,
    // r1->right == r2-->left then return true, do it recursively
    // Here i implement it with an iterative way.
    // It is same like recursive, compare two nodes each time, if
    // they meet the conditions, store their child and go ahead
    vector<TreeNode *> status;
    TreeNode * left, * right;

    // empty
    if (!root)
      return true;
    status.push_back(root);
    status.push_back(root);
    while (!status.empty()) {
      left = status.back();
      status.pop_back();
      right = status.back();
      status.pop_back();
      if (left->left && right->right) {
        if (left->left->val == right->right->val) {
          status.push_back(left->left);
          status.push_back(right->right);
        } else {
          return false;
        }
      } else if ((!left->left && right->right) ||
                 (left->left && !right->right)) {
        // only one is empty
        return false;
      }
      if (left->right && right->left) {
        if (left->right->val == right->left->val) {
          status.push_back(left->right);
          status.push_back(right->left);
        } else {
          return false;
        }
      } else if ((!left->right && right->left) ||
                 (left->right && !right->left)) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  return 0;
}
