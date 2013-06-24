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
*/
#include "binary_tree.h"
#include <cstdio>
#include <queue>
using std::queue;

TreeNode * create_binary_tree(int s[], int n, int term) {
  TreeNode * root = NULL;
  TreeNode * cur = NULL;
  queue<TreeNode *> nodes;
  int i;
  if (n < 1 || s[0] == term)
    return NULL;
  root = new TreeNode(s[0]);
  nodes.push(root);
  for (i = 1; i < n; i++) {
    if (s[i] != term) {
      nodes.front()->left = new TreeNode(s[i]);
      nodes.push(nodes.front()->left);
    }
    ++i;
    if (i < n && s[i] != term) {
      nodes.front()->right = new TreeNode(s[i]);
      nodes.push(nodes.front()->right);
    }
    nodes.pop();
  }
  return root;
}

void print_binary_tree_inorder(TreeNode * root) {
  if (!root)
    return;

  print_binary_tree_inorder(root->left);
  printf("%d ", root->val);
  print_binary_tree_inorder(root->right);
}

void print_binary_tree_preorder(TreeNode * root) {
  if (!root)
    return;
  printf("%d ", root->val);
  print_binary_tree_preorder(root->left);
  print_binary_tree_preorder(root->right);
}

void delete_binary_tree(TreeNode * root) {
  if (!root)
    return;
  delete_binary_tree(root->left);
  delete_binary_tree(root->right);
  delete root;
}
