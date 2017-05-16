class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for ( auto & s : strs ) {
            int one = count(s.begin(), s.end(), '1');
            int zero = s.size() - one;
            for ( int i = zero; i <= m; ++i ) {
                for ( int j = one; j <= n; ++j ) {
                    dp[i-zero][j-one] = max(dp[i-zero][j-one], dp[i][j] + 1);
                }
            }
        }
        return dp[0][0];
    }
};
