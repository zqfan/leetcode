class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> counter(26), window(26);
        for ( char c : s1 ) {
            ++counter[c - 'a'];
        }
        for ( int i = 0; i < n2; ++i ) {
            ++window[s2[i] - 'a'];
            if ( i >= n1 ) {
                --window[s2[i - n1] - 'a'];
            }
            if ( counter == window ) {
                return true;
            }
        }
        return false;
    }
};

// 101 / 101 test cases passed.
// Status: Accepted
// Runtime: 9 ms
