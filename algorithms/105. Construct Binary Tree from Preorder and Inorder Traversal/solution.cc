/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        deque<int> pre(preorder.begin(), preorder.end()), in(inorder.begin(), inorder.end());
        return dfs(pre, in, (TreeNode *)NULL);
    }

    TreeNode * dfs(deque<int> & pre, deque<int> & in, TreeNode * stop) {
        if ( in.empty() || (stop && in.front() == stop->val) ) {
            return NULL;
        }
        TreeNode * root = new TreeNode(pre.front());
        pre.pop_front();
        root->left = dfs(pre, in, root);
        in.pop_front();
        root->right = dfs(pre, in, stop);
        return root;
    }
};

// 202 / 202 test cases passed.
// Status: Accepted
// Runtime: 9 ms
// beats 89.09 %
