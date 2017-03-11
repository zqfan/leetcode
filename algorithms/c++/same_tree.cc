/* Copyright 2013 <ZhiQiang Fan>

   Given two binary trees, write a function to check if they are equal
   or not.
   Two binary trees are considered equal if they are structurally
   identical and the nodes have the same value.
*/
class Solution {
  public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    // both empty
    if (!p && !q)
      return true;
    // one empty
    if (!p || !q)
      return false;
    // neither empty
    if (p->val != q->val)
      return false;

    bool left = this->isSameTree(p->left, q->left);
    if (!left)
      return false;
    return this->isSameTree(p->right, q->right);
  }
};
