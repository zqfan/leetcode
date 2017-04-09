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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }

    TreeNode * dfs(vector<int> & nums, int start, int end) {
        if ( start >= end ) {
            return NULL;
        }
        int m = (start + end) / 2;
        TreeNode * root = new TreeNode(nums[m]);
        root->left = dfs(nums, start, m);
        root->right = dfs(nums, m + 1, end);
        return root;
    }
};

// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 16 ms
