/* Copyright 2013 <ZhiQiang Fan>

   Given an array where elements are sorted in ascending order,
   convert it to a height balanced BST.
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
  TreeNode *sortedArrayToBST(vector<int> &num) {
    vector<int> tmp;
    TreeNode * root = NULL;
    int n;

    if (num.size() < 1)
      return NULL;
    if (num.size() == 1) {
      root = new TreeNode(num[0]);
      return root;
    }

    n = num.size();
    root = new TreeNode(num[n/2]);
    tmp = vector<int>(num.begin(), num.begin() + n/2);
    root->left = this->sortedArrayToBST(tmp);
    tmp = vector<int>(num.begin() + n/2 + 1, num.end());
    root->right = this->sortedArrayToBST(tmp);
    return root;
  }
};

int main() {
  int a[] = {1, 2, 3, 4, 5};
  vector<int> num(a, a+sizeof(a)/sizeof(int));
  Solution s;
  TreeNode * root = s.sortedArrayToBST(num);
  print_binary_tree_inorder(root);
  delete_binary_tree(root);
  return 0;
}
