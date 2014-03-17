/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, return the bottom-up level order traversal of
   its nodes' values. (ie, from left to right, level by level from
   leaf to root).

   For example:
   Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

   return its bottom-up level order traversal as:
   [
   [15,7]
   [9,20],
   [3],
   ]
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include "binary_tree.h"
using std::vector;
using std::queue;
using std::reverse;

class Solution {
  public:
  vector<vector<int> > levelOrderBottom(TreeNode *root) {
    // just using std::reverse, sigh...
    vector<vector<int> > result;
    queue<TreeNode *> nodes;
    TreeNode * cur = NULL;

    if (!root)
      return result;

    nodes.push(root);
    nodes.push(NULL);
    result.push_back(vector<int>());
    while (!nodes.empty()) {
      cur = nodes.front();
      nodes.pop();
      if (!cur && nodes.empty()) {
        break;
      } else if (!cur) {
        nodes.push(NULL);
        result.push_back(vector<int>());
        continue;
      }
      result.back().push_back(cur->val);
      if (cur->left)
        nodes.push(cur->left);
      if (cur->right)
        nodes.push(cur->right);
    }

    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  int n[] = {3, 9, 20, '#', '#', 15, 7};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int), '#');
  Solution s;
  vector<vector<int> > r = s.levelOrderBottom(root);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++)
      printf("%d ", r[i][j]);
    printf("\n");
  }
  delete_binary_tree(root);
  return 0;
}
