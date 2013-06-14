/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, return the inorder traversal of its nodes'
   values.

   For example:
   Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
   return [1,3,2].

   Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <cstdio>
#include <vector>
#include <queue>
#include "binary_tree.h"
using std::vector;
using std::queue;

class Solution {
  public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    vector<TreeNode *> status;

    while (root) {
      // find the left leaf
      while (root->left) {
        status.push_back(root);
        root = root->left;
      }
      status.push_back(root);
      // find right leaf
      do {
        // get last root
        root = status.back();
        status.pop_back();
        result.push_back(root->val);
        root = root->right;
        // if right is not empty or status is empty then break
      } while (!root && !status.empty());
    }

    return result;
  }
};

int main() {
  int n[] = {1, '#', 2, 3};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int), '#');
  Solution s;
  vector<int> r = s.inorderTraversal(root);
  for (int i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  delete_binary_tree(root);
  return 0;
}
