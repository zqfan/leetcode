#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cstddef>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * create_binary_tree(int s[], int n, int term='#');
void print_binary_tree_inorder(TreeNode * root);
void delete_binary_tree(TreeNode * root);

#endif
