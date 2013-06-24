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

Given n, generate all structurally unique BST's (binary search trees)
that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown
below.
    1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
#include <cstdio>
#include <vector>
#include "binary_tree.h"
using std::vector;

class Solution {
  public:
  vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode *> result;
    _gen_trees(result, 1, n);
    return result;
  }

  void _gen_trees(vector<TreeNode *> & trees, int min, int max) {
    vector<TreeNode *> left;
    vector<TreeNode *> right;
    TreeNode * root = NULL;
    int i, j, k;
    if (min > max) {
      trees.push_back(NULL);
      return;
    }
    for (i = min; i <= max; i++) {
      left.clear();
      _gen_trees(left, min, i - 1);
      right.clear();
      _gen_trees(right, i + 1, max);
      for (j = 0; j < left.size(); j++) {
        for (k = 0; k < right.size(); k++) {
          root = new TreeNode(i);
          // must copy the sub tree, or it will mess up
          root->left = _copy_tree(left[j], k);
          root->right = _copy_tree(right[k], j);
          trees.push_back(root);
        }
      }
    }
  }

  TreeNode * _copy_tree(TreeNode * root, int force) {
    if (force == 0)
      return root;
    if (!root)
      return NULL;
    TreeNode * r = new TreeNode(root->val);
    r->left = _copy_tree(root->left, force);
    r->right = _copy_tree(root->right, force);
    return r;
  }
};

int main() {
  Solution s;
  vector<TreeNode *> r = s.generateTrees(10);
  for (int i = 0; i < r.size(); i++) {
    print_binary_tree_preorder(r[i]);
    printf("\n");
    delete_binary_tree(r[i]);
  }
  return 0;
}
