/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree and a sum, find all root-to-leaf paths where
   each path's sum equals the given sum.

   For example:
   Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
   return
   [
   [5,4,11,2],
   [5,8,4,5]
   ]
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include "binary_tree.h"
using std::vector;

class Solution {
  public:
  bool find_path(TreeNode * root, int sum,
                 vector<vector<int> > & result) {
    if (!root)
      return false;
    // leaf node and bingo
    if (!root->left && !root->right && root->val == sum) {
      // new path
      result.push_back(vector<int>());
      result.back().push_back(root->val);
      return true;
    }
    int last = result.size();
    bool left = this->find_path(root->left, sum - root->val, result);
    bool right = this->find_path(root->right, sum - root->val, result);
    // child has path
    if (left || right) {
      for (int i = last; i < result.size(); i++)
        result[i].push_back(root->val);
      return true;
    }
    return false;
  }

  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > result;
    if (!root)
      return result;
    this->find_path(root, sum, result);
    // child path is reverse order, from leaf to root, so reverse it
    for (int i = 0; i < result.size(); i++)
      std::reverse(result[i].begin(), result[i].end());
    return result;
  }
};

int main() {
  int n[] = {5, 4, 8, 11, '#', 13, 4, 7, 2, '#', '#', 5, 1};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int));
  print_binary_tree_inorder(root);
  Solution s;
  vector<vector<int> > r = s.pathSum(root, 22);
  int i, j;
  for (i = 0; i < r.size(); i++) {
    for (j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  delete_binary_tree(root);
  return 0;
}
