class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff = 1, n = preorder.size();
        for ( int i = 0; i <= n; ++i ) {
            if ( i < n && preorder[i] != ',' ) {
                continue;
            }
            if ( --diff < 0 ) {
                return false;
            }
            if ( preorder[i-1] != '#' ) {
                diff += 2;
            }
        }
        return diff == 0;
    }
};
