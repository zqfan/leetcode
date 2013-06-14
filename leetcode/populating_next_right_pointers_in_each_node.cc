/* Copyright 2013 <ZhiQiang Fan>

   Given a binary tree
   struct TreeLinkNode {
   TreeLinkNode *left;
   TreeLinkNode *right;
   TreeLinkNode *next;
   }
   Populate each next pointer to point to its next right node. If
   there is no next right node, the next pointer should be set to NULL.

   Initially, all next pointers are set to NULL.

   Note:

   You may only use constant extra space.
   You may assume that it is a perfect binary tree (ie, all leaves are
   at the same level, and every parent has two children).
   For example,
   Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
   After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
#include <cstdio>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
  public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode * up_level_left = NULL;
    TreeLinkNode * up_level_cur = NULL;
    TreeLinkNode * cur = NULL;
    int m;

    if (!root)
      return;
    up_level_left = up_level_cur = root;
    cur = up_level_left->left;
    m = 1;
    while (cur) {
      if (m % 2 == 1) {
        cur->next = up_level_cur->right;
        up_level_cur = up_level_cur->next;
      } else {
        cur->next = up_level_cur->left;
      }
      m++;
      cur = cur->next;
      if (up_level_cur == NULL) {
        // process next level, initial var and move left pointer to
        // next level
        m = 1;
        up_level_left = up_level_left->left;
        up_level_cur = up_level_left;
        cur = up_level_left->left;
      }
    }
  }
};

int main() {
  return 0;
}
