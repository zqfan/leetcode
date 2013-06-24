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

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you
devise a constant space solution?
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include "binary_tree.h"
using std::vector;

class Solution {
  public:
  void recoverTree(TreeNode *root) {
    TreeNode * first = NULL;
    TreeNode * second = NULL;
    _find_broken_node(root, NULL, &first, &second);
    // swap not occur in recursive call
    if (second)
      // actually, it should swap(root, first) instead of their val
      // but it is more complicated only use constant memory
      std::swap(first->val, second->val);
  }

  // return cur tree rightest node
  // will modify first, second to indicate the broken node
  TreeNode * _find_broken_node(TreeNode * root, TreeNode * prev,
                               TreeNode ** first, TreeNode ** second) {
    if (!root)
      return NULL;
    if (root->left)
      prev = _find_broken_node(root->left, prev, first, second);
    if (prev && root->val < prev->val) {
      // actually, it should swap(root, first) instead of their val
      // but it is more complicated only use constant memory
      if (*first) {
        std::swap(root->val, (*first)->val);
        *second = NULL;
      } else {
        *first = prev;
        *second = root;
      }
    }
    if (root->right)
      return _find_broken_node(root->right, root, first, second);
    else
      return root;
  }
};

int main() {
  int a[] = {4, 2, 5, 1, 3, 6, 7};  // swap 5 and 6
  TreeNode * root = create_binary_tree(a, sizeof(a)/sizeof(int));
  Solution s;
  s.recoverTree(root);
  print_binary_tree_inorder(root);
  delete_binary_tree(root);
  return 0;
}
