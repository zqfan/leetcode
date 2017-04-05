class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for ( int i = n; i > 0; i-- ) {
            for ( int j = i + 1; j <= n; j++ ) {
                dp[i][j] = 0x7fffffff;
                for ( int k = i; k <= j; k++ ) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k-1], dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
