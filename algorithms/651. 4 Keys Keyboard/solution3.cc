class Solution {
public:
    int maxA(int N) {
        int dp[51] = {0};
        for ( int i = 1; i <= N; ++i ) {
            dp[i] = i;
            for ( int j = 3; j < i; ++j )
                dp[i] = max(dp[i], dp[i-j] * (j - 1));
        }
        return dp[N];
    }
};
