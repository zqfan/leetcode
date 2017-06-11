class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int count = 0, n = snums.size();
        for ( int i = 0; i < n; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                auto p = lower_bound(snums.begin() + j + 1, snums.end(), snums[i] + snums[j]);
                count += p - snums.begin() -j - 1;
            }
        }
        return count;
    }
};

// 243 / 243 test cases passed.
// Status: Accepted
// Runtime: 642 ms
