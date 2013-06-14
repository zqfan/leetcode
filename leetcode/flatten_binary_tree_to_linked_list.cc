/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, flatten it to a linked list in-place.

   For example,
   Given
         1
        / \
       2   5
      / \   \
     3   4   6
   The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/
#include "binary_tree.h"

class Solution {
  public:
  TreeNode * _flatten(TreeNode * root) {
    // flatten root, and return last node in pre-order

    if (!root)
      return NULL;
    // leaf node
    if (!root->left && !root->right)
      return root;
    // left is empty, handle right only
    if (!root->left)
      return _flatten(root->right);
    TreeNode * right_child = root->right;
    TreeNode * left_tail = this->_flatten(root->left);
    left_tail->right = right_child;
    root->right = root->left;
    // clear left
    root->left = NULL;
    if (right_child)
      return this->_flatten(root->right);
    // right child is empty, so return last node of left child
    else
      return left_tail;
  }

  void flatten(TreeNode *root) {
    this->_flatten(root);
  }
};

int main() {
  int n[] = {1, 2, 5, 3, 4, '#', 6};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int));
  print_binary_tree_inorder(root);
  Solution s;
  s.flatten(root);
  print_binary_tree_inorder(root);
  delete_binary_tree(root);
  return 0;
}
