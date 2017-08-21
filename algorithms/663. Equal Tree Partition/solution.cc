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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int s = treesum(root, m);
        --m[s];
        return s % 2 == 0 and m[s/2] > 0;
    }

    int treesum(TreeNode * node, unordered_map<int, int> & m) {
        if ( nullptr == node )
            return 0;
        int s = node->val + treesum(node->left, m) + treesum(node->right, m);
        ++m[s];
        return s;
    }
};

// 194 / 194 test cases passed.
// Status: Accepted
// Runtime: 39 ms
