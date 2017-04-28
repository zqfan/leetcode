/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // based on @code9yitati
        string out;
        char buffer[1024];
        dfsEncode(root, out, buffer);
        return out;
    }

    void dfsEncode(TreeNode * root, string & out, char * buffer) {
        if ( root ) {
            memcpy(buffer, & (root->val), sizeof(int));
            out.insert(out.end(), buffer, buffer + sizeof(int));
            dfsEncode(root->left, out, buffer);
            dfsEncode(root->right, out, buffer);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return dfsDecode(data, pos, INT_MIN, INT_MAX);
    }

    TreeNode * dfsDecode(const string & in, int & pos, int minVal, int maxVal) {
        if ( pos >= in.size() ) {
            return NULL;
        }
        int val;
        memcpy(& val, & in[pos], sizeof(int));
        if ( val < minVal || val > maxVal ) {
            return NULL;
        }
        TreeNode * root = new TreeNode(val);
        pos += sizeof(int);
        root->left = dfsDecode(in, pos, minVal, val);
        root->right = dfsDecode(in, pos, val, maxVal);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// 62 / 62 test cases passed.
// Status: Accepted
// Runtime: 19 ms
// beats 97.10 %
