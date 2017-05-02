/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        if ( root ) {
            s.push(root);
            while ( s.top()->left ) {
                s.push(s.top()->left);
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return s.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * node = s.top();
        s.pop();
        if ( node->right ) {
            s.push(node->right);
            while ( s.top()->left ) {
                s.push(s.top()->left);
            }
        }
        return node->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
