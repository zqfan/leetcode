/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, return the zigzag level order traversal of its
   nodes' values. (ie, from left to right, then right to left for the
   next level and alternate between).

   For example:
   Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

   return its zigzag level order traversal as:
   [
   [3],
   [20,9],
   [15,7]
   ]
*/
#include <cstdio>
#include <vector>
#include <deque>
#include "binary_tree.h"
using std::vector;
using std::deque;

class Solution {
  public:
  vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    int direction = 0;  // 0: from left to right, 1 reverse
    vector<vector<int> > result;
    deque<TreeNode *> nodes;
    TreeNode * cur = NULL;

    if (!root)
      return result;

    result.push_back(vector<int>());
    nodes.push_back(root);
    nodes.push_back(NULL);
    while (!nodes.empty()) {
      if (direction == 0) {
        cur = nodes.front();
        nodes.pop_front();
      } else {
        cur = nodes.back();
        nodes.pop_back();
      }
      // every node is accessed
      if (!cur && nodes.empty()) {
        return result;
      } else if (!cur) {
        // reverse direction
        direction = 1 - direction;
        // push a flag to indicate level end
        if (direction == 0)
          nodes.push_back(NULL);
        else
          nodes.push_front(NULL);
        result.push_back(vector<int>());
        continue;
      }
      // cur is not NULL
      result.back().push_back(cur->val);
      if (direction == 0) {
        if (cur->left)
          nodes.push_back(cur->left);
        if (cur->right)
          nodes.push_back(cur->right);
      } else {
        if (cur->right)
          nodes.push_front(cur->right);
        if (cur->left)
          nodes.push_front(cur->left);
      }
    }
  }
};

int main() {
  int s[] = {3, 9, 20, '#', '#', 15, 7};
  TreeNode * root = create_binary_tree(s, sizeof(s)/sizeof(int), '#');
  print_binary_tree_inorder(root);
  Solution sol;
  vector<vector<int> > r = sol.zigzagLevelOrder(root);
  for (int i = 0; i < r.size(); i++) {
    for (int j = 0; j < r[i].size(); j++) {
      printf("%d ", r[i][j]);
    }
    printf("\n");
  }
  delete_binary_tree(root);
  return 0;
}
