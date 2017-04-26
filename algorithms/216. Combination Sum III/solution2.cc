class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> bitmask(k, 1), comb;
        bitmask.resize(9, 0);
        vector<vector<int>> result;
        do {
            comb.clear();
            for ( int i = 0; i < 9; ++i ) {
                if ( bitmask[i] ) {
                    comb.push_back(i + 1);
                }
            }
            if ( accumulate(comb.begin(), comb.end(), 0) == n ) {
                result.push_back(comb);
            }
        } while ( prev_permutation(bitmask.begin(), bitmask.end()));
        return result;
    }
};

// 18 / 18 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// beats 3.13 %
