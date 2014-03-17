/* Copyright 2013 <ZhiQiang Fan>

   Follow up for problem "Populating Next Right Pointers in Each Node".
   What if the given tree could be any binary tree? Would your
   previous solution still work?

   Note:
   You may only use constant extra space.
   For example,
   Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7
    After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
    // the main problem is up_level_cur left child and right child
    // can be none
    TreeLinkNode * cur_level_left = NULL;
    TreeLinkNode * up_level_cur = NULL;
    TreeLinkNode * cur = NULL;

    if (!root)
      return;
    up_level_cur = root;
    while (true) {
      // process cur level from left to right, up level should not be
      // null if cur level still have nodes
      while (up_level_cur) {
        // in process
        if (cur) {
          if (up_level_cur->left) {
            cur->next = up_level_cur->left;
            cur = cur->next;
          }
          if (up_level_cur->right) {
            cur->next = up_level_cur->right;
            cur = cur->next;
          }
        } else {  // cur is null means new level is start
          if (up_level_cur->left) {
            cur_level_left = cur = up_level_cur->left;
            // try to move to next node, to avoid some compare
            if (up_level_cur->right) {
              cur->next = up_level_cur->right;
              cur = cur->next;
            }
          } else if (up_level_cur->right) {
            cur_level_left = cur = up_level_cur->right;
          }
        }
        // up level move to next
        up_level_cur = up_level_cur->next;
      }  // end of while up_level_cur
      // now up_level_cur is null
      // if we find a node in current level
      if (cur_level_left) {
        // process next level
        up_level_cur = cur_level_left;
        cur = NULL;  // same as cur = cur->next
        cur_level_left = NULL;
      } else {  // no more node to process
        return;
      }
    }  // end of while true
  }
};

int main() {
  return 0;
}
