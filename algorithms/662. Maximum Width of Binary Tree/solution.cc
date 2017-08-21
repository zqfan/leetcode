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
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> leftmost;
        int maxwidth = 0;
        dfs(root, 0, 0, leftmost, maxwidth);
        return maxwidth;
    }

    void dfs(TreeNode * node, int h, int w, vector<int> & leftmost, int & maxwidth){
        if ( node ) {
            if ( h >= leftmost.size() )
                leftmost.push_back(w);
            maxwidth = max(maxwidth, w - leftmost[h] + 1);
            dfs(node->left, h + 1, w * 2, leftmost, maxwidth);
            dfs(node->right, h + 1, w * 2 + 1, leftmost, maxwidth);
        }
    }
};

// 108 / 108 test cases passed.
// Status: Accepted
// Runtime: 6 ms
