class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ( sum & 1 ) return false;
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for ( int n : nums ) {
            for ( int i = sum; i >= 0; --i ) {
                if ( i + n <= sum ) {
                    dp[i + n] |= dp[i];
                }
            }
        }
        return dp[sum / 2];
    }
};
