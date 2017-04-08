class Solution {
public:
    string reverseStr(string s, int k) {
        for ( int i = 0; i < s.size(); i += 2 * k ) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};

// 60 / 60 test cases passed.
// Status: Accepted
// Runtime: 9 ms
