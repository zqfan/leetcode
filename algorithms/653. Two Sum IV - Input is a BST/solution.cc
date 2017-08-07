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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> counter;
        dfs(counter, root);
        for ( auto & p : counter ) {
            if ( 2 * p.first == k ) {
                if ( p.second > 1 )
                    return true;
            } else if ( counter.count(k - p.first) )
                return true;
        }
        return false;
    }

    void dfs(unordered_map<int, int> & counter, TreeNode * root) {
        if ( root ) {
            ++counter[root->val];
            dfs(counter, root->left);
            dfs(counter, root->right);
        }
    }
};

// 421 / 421 test cases passed.
// Status: Accepted
// Runtime: 63 ms
