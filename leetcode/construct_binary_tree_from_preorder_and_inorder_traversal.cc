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

Given preorder and inorder traversal of a tree, construct the binary
tree.
Note:
You may assume that duplicates do not exist in the tree.
*/
#include "binary_tree.h"
#include <cstdio>
#include <vector>
using std::vector;

class Solution {
  public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return _build_tree(preorder, 0, preorder.size(),
                       inorder, 0, inorder.size());
  }

  TreeNode * _build_tree(vector<int> & preorder, int lp, int rp,
                         vector<int> & inorder, int li, int ri) {
    if (lp >= rp || li >= ri)
      return NULL;
    int i;
    // find the root val in inorder, the left side of inorder is left
    // child tree
    for (i = li; i < ri; i++) {
      if (inorder[i] == preorder[lp])
        break;
    }
    TreeNode * root = new TreeNode(preorder[lp]);
    root->left = _build_tree(preorder, lp+1, lp+1+i-li,
                             inorder, li, i);
    root->right = _build_tree(preorder, lp+1+i-li, rp,
                              inorder, i+1, ri);
    return root;
  }
};

int main() {
  int p[] = {1, 2, 4, 5, 3, 6, 7};
  vector<int> preorder(p, p+sizeof(p)/sizeof(int));
  int i[] = {4, 2, 5, 1, 6, 3, 7};
  vector<int> inorder(i, i+sizeof(i)/sizeof(int));
  Solution s;
  TreeNode * root = s.buildTree(preorder, inorder);
  print_binary_tree_inorder(root);
  delete_binary_tree(root);
  return 0;
}
