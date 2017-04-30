class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if ( n * m != r * c ) {
            return nums;
        }
        vector<vector<int>> result;
        for ( int i = 0, count = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( count % c == 0 ) {
                    result.push_back(vector<int>());
                }
                ++count;
                result.back().push_back(nums[i][j]);
            }
        }
        return result;
    }
};

// 56 / 56 test cases passed.
// Status: Accepted
// Runtime: 39 ms
// beats 100.00 %
