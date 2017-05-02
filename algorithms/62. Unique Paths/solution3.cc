class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101] = {0};
        dp[0][1] = 1;
        for ( int i = 1; i <= m; ++i ) {
            for ( int j = 1; j <= n; ++j ) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};

// 61 / 61 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// beats 2.91 %
