class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001] = {0};
        for ( int i = 0; i < s1.size(); ++i ) {
            for ( int j = 0; j < s2.size(); ++j ) {
                if ( s1[i] == s2[j] ) {
                    dp[i+1][j+1] = dp[i][j] + int(s1[i]) * 2;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int n1 = accumulate(s1.begin(), s1.end(), 0);
        int n2 = accumulate(s2.begin(), s2.end(), 0);
        return n1 + n2 - dp[s1.size()][s2.size()];
    }
};

// 94 / 94 test cases passed.
// Status: Accepted
// Runtime: 55 ms
