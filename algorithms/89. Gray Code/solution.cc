class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for ( int i = 0, limit = 1 << n; i < limit; ++i ) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};

// 12 / 12 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// beats 57.78 %
