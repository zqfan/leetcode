class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counter;
        for ( int i = 0, limit = s.size() - 9; i < limit; ++i ) {
            ++counter[s.substr(i, 10)];
        }
        vector<string> result;
        for ( auto & p : counter ) {
            if ( p.second > 1 ) {
                result.push_back(p.first);
            }
        }
        return result;
    }
};

// 32 / 32 test cases passed.
// Status: Accepted
// Runtime: 75 ms
// beats 51.25 %
