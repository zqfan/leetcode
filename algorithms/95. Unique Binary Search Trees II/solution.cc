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
    vector<TreeNode*> generateTrees(int n) {
        return n > 0 ? gen(1, n) : vector<TreeNode *>();
    }

    vector<TreeNode *> gen(int start, int end) {
        vector<TreeNode *> result;
        for ( int i = start; i <= end; ++i ) {
            for ( TreeNode * left : gen(start, i - 1) ) {
                for ( TreeNode * right : gen(i + 1, end) ) {
                    TreeNode * root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result.size() ? result : vector<TreeNode *> (1, NULL);
    }
};

// 9 / 9 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// beats 41.12 %
