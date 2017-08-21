class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        int dp[101][101] = {0};
        for ( int i = 0; i < n; ++i )
            dp[i][i] = 1;
        for ( int l = 1; l < n; ++l ) {
            for ( int i = 0; i + l < n; ++i ) {
                dp[i][i+l] = dp[i+1][i+l] + 1;
                for ( int j = i + 1; j <= i + l; ++j )
                    if ( s[i] == s[j] )
                        dp[i][i+l] = min(dp[i][i+l], dp[i][j-1] + dp[j+1][i+l]);
            }
        }
        return n ? dp[0][n-1] : 0;
    }
};

// 201 / 201 test cases passed.
// Status: Accepted
// Runtime: 22 ms
