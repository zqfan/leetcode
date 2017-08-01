class Solution {
public:
    int countSubstrings(string s) {
        // @ hao-cai
        int cnt = 0, n = s.size();
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; ++j )
                ++cnt;
            for ( int j = 0; i-j-1 >= 0 && i+j < n && s[i-j-1] == s[i+j]; ++j )
                ++cnt;
        }
        return cnt;
    }
};

// 130 / 130 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 67.19 %
