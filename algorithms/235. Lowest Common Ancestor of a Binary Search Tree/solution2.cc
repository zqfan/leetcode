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
    TreeNode * lca = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return lca;
    }

    int dfs(TreeNode * root, TreeNode * p, TreeNode * q) {
        if ( NULL == root ) {
            return 0;
        }
        int find = dfs(root->left, p, q) + dfs(root->right, p, q);
        if ( root == p || root == q ) {
            ++find;
        }
        if ( 2 == find && NULL == lca ) {
            lca = root;
        }
        return find;
    }
};
