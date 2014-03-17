/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree, return the level order traversal of its nodes'
   values. (ie, from left to right, level by level).

   For example:
   Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
   return its level order traversal as:

   [
   [3],
   [9,20],
   [15,7]
   ]
*/
class Solution {
  public:
  vector<vector<int> > levelOrder(TreeNode *root) {
    queue<TreeNode *> status;
    vector<vector<int> > result;
    TreeNode * cur = NULL;

    if (!root)
      return result;

    result.push_back(vector<int>());
    status.push(root);
    status.push(NULL);
    while (!status.empty()) {
      cur = status.front();
      status.pop();
      // every node is accessed
      if (!cur && status.empty()) {
        return result;
      } else if (!cur) {
        // push a flag to indicate level end
        status.push(NULL);
        result.push_back(vector<int>());
        continue;
      }
      // cur is not NULL
      result.back().push_back(cur->val);
      if (cur->left)
        status.push(cur->left);
      if (cur->right)
        status.push(cur->right);
    }
  }
};
