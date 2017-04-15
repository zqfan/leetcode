class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if ( m == 0 ) {
            return 0;
        }
        vector<int> dp(n);
        for ( int i = 1, j = 0; i < m; ) {
            if ( needle[i] == needle[j] ) {
                dp[i++] = ++j;
            } else if ( j == 0 ) {
                ++i;
            } else {
                j = dp[j - 1];
            }
        }
        for ( int i = 0, j = 0; i < n; ) {
            if ( haystack[i] == needle[j] ) {
                if ( j == m - 1 ) {
                    return i - j;
                }
                ++i;
                ++j;
            } else if ( j == 0 ) {
                ++i;
            } else {
                j = dp[j - 1];
            }
        }
        return -1;
    }
};
