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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode *> s;
        for ( int n : nums ) {
            TreeNode * cur = new TreeNode(n);
            while ( s.size() > 0 && s.back()->val < n ) {
                cur->left = s.back();
                s.pop_back();
            }
            if ( s.size() > 0 )
                s.back()->right = cur;
            s.push_back(cur);
        }
        return s[0];
    }
};

// 107 / 107 test cases passed.
// Status: Accepted
// Runtime: 62 ms
