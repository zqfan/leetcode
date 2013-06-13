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
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * create_binary_tree() {
  TreeNode * root = NULL;
  root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  return root;
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
  TreeNode * root = create_binary_tree();
  Solution s;
  vector<int> r = s.inorderTraversal(root);
  for (int i = 0; i < r.size(); i++)
    printf("%d ", r[i]);
  printf("\n");
  return 0;
}
