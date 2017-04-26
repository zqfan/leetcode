class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ( S > sum || ((S + sum) & 1) ) {
            return 0;
        }
        int s = (S + sum) >> 1;
        vector<int> dp(s + 1);
        dp[0] = 1;
        for ( int n : nums ) {
            for ( int i = s; i >= n; --i ) {
                dp[i] += dp[i - n];
            }
        }
        return dp[s];
    }
};

// 139 / 139 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 76.92 %
