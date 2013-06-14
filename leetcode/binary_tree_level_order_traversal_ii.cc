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
using std::vector;
using std::queue;
using std::reverse;

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
