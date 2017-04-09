class Solution {
public:
    string reverseWords(string s) {
        for ( int i = 0, pre = 0; i <= s.size(); ++i ) {
            if ( i == s.size() || s[i] == ' ' ) {
                reverse(s.begin() + pre, s.begin() + i);
                pre = i + 1;
            }
        }
        return s;
    }
};

// 30 / 30 test cases passed.
// Status: Accepted
// Runtime: 22 ms
