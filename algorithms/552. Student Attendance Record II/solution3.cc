class Solution {
public:
    int checkRecord(int n) {
        // based on @lixx2100
        int m = 1000000007;
        int f[100001][2][3] = {1, 1, 1, 1, 1, 1};
        for ( int i = 1; i <= n; ++i ) {
            for ( int j = 0; j < 2; ++j ) {
                for ( int k = 0; k < 3; ++k ) {
                    // append P
                    f[i][j][k] = f[i - 1][j][2];
                    if ( j > 0 ) {
                        // append A
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][2]) % m;
                    }
                    if ( k > 0 ) {
                        // append L
                        f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1]) % m;
                    }
                }
            }
        }
        return f[n][1][2];
    }
};

// 58 / 58 test cases passed.
// Status: Accepted
// Runtime: 149 ms
