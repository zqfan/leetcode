/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, find its minimum depth.
   The minimum depth is the number of nodes along the shortest path
   from the root node down to the nearest leaf node.
*/
#include <cstdio>
#include <queue>
#include "binary_tree.h"
using std::queue;

class Solution {
  public:
  int minDepth(TreeNode *root) {
    if (!root)
      return 0;

    TreeNode * cur = NULL;
    queue<TreeNode *> nodes;
    int depth = 0;
    nodes.push(root);
    nodes.push(NULL);
    while (!nodes.empty()) {
      cur = nodes.front();
      nodes.pop();
      if (!cur && nodes.empty()) {
        return ++depth;
      } else if (!cur) {
        ++depth;
        nodes.push(NULL);
        continue;
      }
      if (!cur->left && !cur->right)
        return ++depth;
      if (cur->left)
        nodes.push(cur->left);
      if (cur->right)
        nodes.push(cur->right);
    }
  }
};

int main() {
  int n[] = {1, 2, 3, 4};
  TreeNode * root = create_binary_tree(n, sizeof(n)/sizeof(int));
  Solution s;
  printf("%d\n", s.minDepth(root));
  delete_binary_tree(root);
  return 0;
}
