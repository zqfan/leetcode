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
        queue<TreeNode *> q;
        q.push(root);
        while ( ! q.empty() ) {
            auto p = q.front();
            q.pop();
            s.insert(p->val);
            if ( p->left )
                q.push(p->left);
            if ( p->right )
                q.push(p->right);
        }
        s.erase(s.begin());
        return s.empty() ? -1 : *s.begin();
    }
};

// 34 / 34 test cases passed.
// Status: Accepted
// Runtime: 3 ms
