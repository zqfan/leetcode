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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string strs, strt;
        serialize(s, strs);
        serialize(t, strt);
        return (',' + strs).find(',' + strt) != string::npos;
    }

    void serialize(TreeNode * root, string & out) {
        if ( root ) {
            out += "," + to_string(root->val);
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out += ",#";
        }
    }
};

// 174 / 174 test cases passed.
// Status: Accepted
// Runtime: 32 ms
