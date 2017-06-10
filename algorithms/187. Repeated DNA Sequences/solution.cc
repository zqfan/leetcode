class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // @1337c0d3r
        unordered_map<int, int> counter;
        vector<string> result;
        for ( int t = 0, i = 0, n = s.size(); i < n; ++i )
            if ( ++counter[t = t << 3 & 0x3FFFFFFF | s[i] & 7] == 2 )
                result.push_back(s.substr(i - 9, 10));
        return result;
    }
};

// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 56 ms
// beats 72.83 %
