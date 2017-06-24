class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxlen = 0, n = s.size();
        for ( int i = 0, l, r; i < n; ++i ) {
            for ( l = r = i; l >= 0 && r < n && s[--l] == s[++r]; ) ;
            if ( r - l - 1 > maxlen )
                start = l + 1;
            maxlen = max(maxlen, r - l - 1);
            for ( l = i + 1, r = i; l >= 0 && r < n && s[--l] == s[++r]; ) ;
            if ( r - l - 1 > maxlen )
                start = l + 1;
            maxlen = max(maxlen, r - l - 1);
        }
        return s.substr(start, maxlen);
    }
};
