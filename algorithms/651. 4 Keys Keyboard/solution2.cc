class Solution {
public:
    int maxA(int N) {
        int dp[51] = {0};
        for ( int i = 1; i < 7; ++i )
            dp[i] = i;
        for ( int i = 7; i <= N; ++i )
            dp[i] = max(dp[i-4] * 3, dp[i-5] * 4);
        return dp[N];
    }
};
