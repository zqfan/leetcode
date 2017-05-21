class Solution {
public:
    int longestSubstring(string s, int k) {
        for ( char c : set<char> (s.begin(), s.end()) ) {
            if ( count(s.begin(), s.end(), c) < k ) {
                int p0 = 0, p1 = s.find(c), maxlen = 0;
                while ( 1 ) {
                    maxlen = max(maxlen, longestSubstring(s.substr(p0, p1-p0), k));
                    if ( p1 == string::npos ) {
                        return maxlen;
                    }
                    p0 = p1 + 1;
                    p1 = s.find(c, p1 + 1);
                }
            }
        }
        return s.size();
    }
};

// 28 / 28 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 60.55 %
