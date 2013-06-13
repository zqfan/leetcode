/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, find its maximum depth.
   The maximum depth is the number of nodes along the longest path
   from the root node down to the farthest leaf node.
*/
#include <cstdio>
#include <vector>
#include <queue>
using std::vector;
using std::queue;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * create_binary_tree(int s[], int n, int term=-1) {
  TreeNode * root = NULL;
  TreeNode * cur = NULL;
  vector<TreeNode *> nodes;
  int i;
  if (s[0] == 0 || s[0] == '#')
    return NULL;
  root = new TreeNode(s[0]);
  nodes.push_back(root);
  for (i = 0; 2*i+2 < n; i++) {
    if (s[2*i+1] == '#')
      nodes[i]->left = NULL;
    else
      nodes[i]->left = new TreeNode(s[2*i + 1]);
    nodes.push_back(nodes[i]->left);
    if (s[2*i+2] == '#')
      nodes[i]->right = NULL;
    else
      nodes[i]->right = new TreeNode(s[2*i + 2]);
    nodes.push_back(nodes[i]->right);
  }
  return root;
}

void print_binary_tree_inorder(TreeNode * root) {
  if (!root)
    return;

  print_binary_tree_inorder(root->left);
  printf("%d ", root->val);
  print_binary_tree_inorder(root->right);
}

void delete_binary_tree(TreeNode * root) {
  if (!root)
    return;
  delete_binary_tree(root->left);
  delete_binary_tree(root->right);
  delete root;
}

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
