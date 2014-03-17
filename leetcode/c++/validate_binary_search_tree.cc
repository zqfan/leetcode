/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, determine if it is a valid binary search tree
   (BST).

   Assume a BST is defined as follows:

   * The left subtree of a node contains only nodes with keys less
   than the node's key.
   * The right subtree of a node contains only nodes with keys greater
   than the node's key.
   * Both the left and right subtrees must also be binary search trees.
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

class Solution {
  public:
  bool isValidBST(TreeNode *root) {
    if (NULL == root)
      return true;

    TreeNode * cur = NULL;
    vector<TreeNode *> nodes;
    // bounds[i][0] = min, bounds[i][1] = max
    vector<vector<int> > bounds;
    vector<int> tmp, next_bounds;

    tmp = vector<int>(2, root->val);
    nodes.push_back(root);
    bounds.push_back(tmp);

    while (!nodes.empty()) {
      // get a valid node
      cur = nodes.back();
      nodes.pop_back();
      tmp = bounds.back();
      bounds.pop_back();
      if (cur->left) {
        // if cur node's left larger than cur or cur is on the right
        // side and cur left less than cur's father
        if (cur->left->val >= cur->val ||
            (cur->val > tmp[0] && cur->left->val <= tmp[0]))
          return false;
        // left is valid
        nodes.push_back(cur->left);
        next_bounds = tmp;
        next_bounds[1] = cur->val;
        bounds.push_back(next_bounds);
      }
      if (cur->right) {
        if (cur->right->val <= cur->val ||
            (cur->val < tmp[1] && cur->right->val >= tmp[1]))
          return false;
        nodes.push_back(cur->right);
        next_bounds = tmp;
        next_bounds[0] = cur->val;
        bounds.push_back(next_bounds);
      }
    }
    return true;
  }
};

int main() {
  return 0;
}
