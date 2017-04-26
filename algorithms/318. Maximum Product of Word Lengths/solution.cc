class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), mp = 0;
        vector<int> bitmask(n);
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < words[i].size(); ++j ) {
                bitmask[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for ( int i = 0; i < n; ++i ) {
            for ( int j = i + 1; j < n; j++ ) {
                if ( (bitmask[i] & bitmask[j]) == 0 ) {
                    mp = max(mp, int(words[i].size() * words[j].size()));
                }
            }
        }
        return mp;
    }
};

// 174 / 174 test cases passed.
// Status: Accepted
// Runtime: 45 ms
// beats 86.98 %
