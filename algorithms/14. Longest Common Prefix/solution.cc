class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size(), pos = 0;
        string lcp;
        if ( n < 1 ) {
            return lcp;
        }
        while ( true ) {
            for ( int i = 0; i < n; ++i ) {
                if ( pos >= strs[i].size() ) {
                    return lcp;
                }
                if ( i > 0 && strs[i][pos] != strs[i-1][pos] ) {
                    return lcp;
                }
            }
            lcp += strs[0][pos];
            ++pos;
        }
    }
};
