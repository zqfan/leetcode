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

Given inorder and postorder traversal of a tree, construct the binary
tree.
Note:
You may assume that duplicates do not exist in the tree.
*/
#include "binary_tree.h"
#include <vector>
using std::vector;

class Solution {
  public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return _build_tree(inorder, 0, inorder.size(),
                       postorder, 0, postorder.size());
  }

  TreeNode * _build_tree(vector<int> & inorder, int li, int ri,
                         vector<int> & postorder, int lp, int rp) {
    if (li >= ri || lp >= rp)
      return NULL;
    int i;
    // find the root val, and process left part and right part
    for (i = li; i < ri; i++) {
      if (inorder[i] == postorder[rp-1])
        break;
    }
    TreeNode * root = new TreeNode(postorder[rp-1]);
    root->left = _build_tree(inorder, li, i,
                             postorder, lp, lp+i-li);
    root->right = _build_tree(inorder, i+1, ri,
                              postorder, lp+i-li, rp-1);
    return root;
  }
};

int main() {
  int i[] = {4, 2, 5, 1, 6, 3, 7};
  int p[] = {4, 5, 2, 6, 7, 3, 1};
  vector<int> inorder(i, i+sizeof(i)/sizeof(int));
  vector<int> postorder(p, p+sizeof(p)/sizeof(int));
  Solution s;
  TreeNode * root = s.buildTree(inorder, postorder);
  print_binary_tree_inorder(root);
  delete_binary_tree(root);
  return 0;
}
