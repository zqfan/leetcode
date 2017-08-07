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
        return dfs(nums, nums.begin(), nums.end());
    }

    TreeNode * dfs(vector<int> & nums, vector<int>::iterator left, vector<int>::iterator right) {
        if ( left >= right )
            return nullptr;
        auto pmax = max_element(left, right);
        TreeNode * root = new TreeNode(*pmax);
        root->left = dfs(nums, left, pmax);
        root->right = dfs(nums, pmax + 1, right);
        return root;
    }
};

// 107 / 107 test cases passed.
// Status: Accepted
// Runtime: 59 ms
