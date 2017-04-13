class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> counter(26);
        for ( char c : p ) {
            ++counter[c - 'a'];
        }
        vector<int> window(26);
        int n = s.size(), m = p.size();
        for ( int i = 0; i < n; ++i ) {
            ++window[s[i] - 'a'];
            if ( i >= m ) {
                --window[s[i - m] - 'a'];
            }
            if ( window == counter ) {
                result.push_back(i - m + 1);
            }
        }
        return result;
    }
};

// 36 / 36 test cases passed.
// Status: Accepted
// Runtime: 33 ms
// beats 87.52%
