class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // diff of play1 and play2 in range i...j inclusive
        int dp[20][20] = {0};
        int n = nums.size();
        for ( int i = n - 1; i >= 0; i-- ) {
            dp[i][i] = nums[i];
            for ( int j = i + 1; j < n; j++ ) {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] >= 0;
    }
};
