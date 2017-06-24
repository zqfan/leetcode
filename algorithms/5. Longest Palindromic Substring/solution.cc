class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, maxlen = 1;
        for ( int i = 0, l, r; i < n - 1; ) {
            l = r = i;
            while ( s[r] == s[r + 1] )
                ++r;
            i = r + 1;
            while ( l > 0 && r + 1 < n && s[l - 1] == s[r + 1] ) {
                --l;
                ++r;
            }
            if ( r - l + 1 > maxlen ) {
                maxlen = r - l + 1;
                start = l;
            }
        }
        return s.substr(start, maxlen);
    }
};

// 94 / 94 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 78.61 %
