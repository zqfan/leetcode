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
        vector<vector<int> > result;
        queue<TreeNode *> nodes;
        TreeNode * cur = NULL;

        if (!root)
            return result;

        nodes.push(root);
        nodes.push(NULL);
        result.push_back(vector<int>());
        while (!nodes.empty()) {
            cur = nodes.front();
            nodes.pop();
            if (!cur && nodes.empty()) {
                break;
            } else if (!cur) {
                nodes.push(NULL);
                result.push_back(vector<int>());
                continue;
            }
            result.back().push_back(cur->val);
            if (cur->left)
                nodes.push(cur->left);
            if (cur->right)
                nodes.push(cur->right);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
