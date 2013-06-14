/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree and a sum, determine if the tree has a
   root-to-leaf path such that adding up all the values along the path
   equals the given sum.

   For example:
   Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
   return true, as there exist a root-to-leaf path 5->4->11->2 which
   sum is 22.
*/
#include "binary_tree.h"

class Solution {
  public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root)
      return false;

    // if it is leaf node
    if (!root->left && !root->right)
      return root->val == sum;

    bool left = this->hasPathSum(root->left, sum - root->val);
    return left || this->hasPathSum(root->right, sum - root->val);
  }
};

int main() {
  return 0;
}
