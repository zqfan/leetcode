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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        dfs(root, s);
        s.erase(s.begin());
        return s.empty() ? -1 : *s.begin();
    }

    void dfs(TreeNode * p, set<int> & s) {
        if ( p ) {
            s.insert(p->val);
            dfs(p->left, s);
            dfs(p->right, s);
        }
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 3 ms
