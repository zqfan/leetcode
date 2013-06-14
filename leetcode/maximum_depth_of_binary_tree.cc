/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, find its maximum depth.
   The maximum depth is the number of nodes along the longest path
   from the root node down to the farthest leaf node.
*/
#include <cstdio>
#include <vector>
#include <queue>
#include "binary_tree.h"
using std::vector;
using std::queue;

class Solution {
  public:
  int maxDepth(TreeNode *root) {
    queue<TreeNode *> nodes;
    TreeNode * cur = NULL;
    int depth = 0;

    if (!root)
      return 0;

    nodes.push(root);
    nodes.push(NULL);
    while (!nodes.empty()) {
      cur = nodes.front();
      nodes.pop();
      if (!cur && !nodes.empty()) {
        depth++;
        nodes.push(NULL);
        continue;
      } else if (!cur) {
        return depth + 1;
      }
      if (cur->left)
        nodes.push(cur->left);
      if (cur->right)
        nodes.push(cur->right);
    }
  }
};

int main() {
  int n[] = {3, 9, 20, '#', '#', 15, 7};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int), '#');
  Solution s;
  printf("%d\n", s.maxDepth(root));
  delete_binary_tree(root);
  return 0;
}
