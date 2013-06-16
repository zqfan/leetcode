/* Copyright 2013 <ZhiQiang Fan>

   Given preorder and inorder traversal of a tree, construct the
   binary tree.

   Note:
   You may assume that duplicates do not exist in the tree.
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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    
  }
};

int main() {
  return 0;
}
