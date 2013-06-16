/* Copyright 2013 <ZhiQiang Fan>

   Two elements of a binary search tree (BST) are swapped by mistake.

   Recover the tree without changing its structure.

   Note:
   A solution using O(n) space is pretty straight forward. Could you
   devise a constant space solution?
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
  void recoverTree(TreeNode *root) {
    
  }
};
