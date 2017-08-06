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
    unordered_map<string, vector<TreeNode *>> mem;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        vector<TreeNode *> result;
        for ( auto & p : mem )
            if ( p.second.size() > 1 )
                result.push_back(p.second[0]);
        return result;
    }

    string serialize(TreeNode * node) {
        if ( ! node )
            return "";
        string left = "," + serialize(node->left);
        string right = "," + serialize(node->right);
        string s = to_string(node->val) + left + right;
        mem[s].push_back(node);
        return s;
    }
};

// 167 / 167 test cases passed.
// Status: Accepted
// Runtime: 28 ms
// beats 82.61 %
