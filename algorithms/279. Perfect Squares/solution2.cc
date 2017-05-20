class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while ( dp.size() <= n ) {
            int m = dp.size(), cnt = INT_MAX;
            for ( int j = 1; j * j <= m; ++j ) {
                cnt = min(cnt, dp[m - j * j] + 1);
            }
            dp.push_back(cnt);
        }
        return dp[n];
    }
};
