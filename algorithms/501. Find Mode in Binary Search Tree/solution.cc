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
    int pre = 0;
    int curCount = 0;
    int maxCount = 0;
public:
    vector<int> findMode(TreeNode* root) {
        findMaxCount(root);
        curCount = 0;
        vector<int> mode;
        findMode(root, mode);
        return mode;
    }
    
    void findMaxCount(TreeNode * root) {
        if ( root ) {
            findMaxCount(root->left);
            if ( pre != root->val ) {
                curCount = 0;
                pre = root->val;
            }
            ++curCount;
            maxCount = max(maxCount, curCount);
            findMaxCount(root->right);
        }
    }

    void findMode(TreeNode * root, vector<int> & mode) {
        if ( root ) {
            findMode(root->left, mode);
            if ( pre != root->val ) {
                curCount = 0;
                pre = root->val;
            }
            ++curCount;
            if ( curCount == maxCount ) {
                mode.push_back(root->val);
            }
            findMode(root->right, mode);
        }
    }
};
