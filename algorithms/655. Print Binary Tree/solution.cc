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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root), w = (1<<h) - 1;
        vector<vector<string>> result(h, vector<string> (w));
        write(result, root, 0, w, 0);
        return result;
    }

    int getHeight(TreeNode * node) {
        return node ? max(getHeight(node->left), getHeight(node->right)) + 1 : 0;
    }

    void write(vector<vector<string>> & m, TreeNode * node, int h, int w, int w0) {
        if ( node ) {
            m[h][w0+w/2] = to_string(node->val);
            write(m, node->left, h+1, w/2, w0);
            write(m, node->right, h+1, w/2, w0+w/2+1);
        }
    }
};

// 73 / 73 test cases passed.
// Status: Accepted
// Runtime: 3 ms
