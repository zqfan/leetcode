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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if ( NULL == root ) {
            return result;
        }
        vector<TreeNode *> level(1, root);
        vector<TreeNode *> nextLevel;
        while ( level.size() > 0 ) {
            result.push_back(vector<int> ());
            for ( auto node : level ) {
                result.back().push_back(node->val);
                if ( node->left ) {
                    nextLevel.push_back(node->left);
                }
                if ( node->right ) {
                    nextLevel.push_back(node->right);
                }
            }
            level = nextLevel;
            nextLevel.clear();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// beats 88.34%
