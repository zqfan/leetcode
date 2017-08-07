class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        int n = A.size();
        vector<int> dp(n, INT_MAX), pos(n, -1);
        dp[n-1] = A[n-1];
        for ( int i = n - 2; i >= 0; --i ) {
            if ( -1 == A[i] )
                continue;
            int limit = min(n, i + B + 1);
            for ( int j = i + 1; j < limit; ++j ) {
                if ( INT_MAX == dp[j] )
                    continue;
                if ( dp[j] + A[i] < dp[i] ) {
                    dp[i] = dp[j] + A[i];
                    pos[i] = j;
                }
            }
        }
        vector<int> result;
        if ( INT_MAX == dp[0] || -1 == A.back() )
            return result;
        int k = 0;
        while ( -1 != k ) {
            result.push_back(k + 1);
            k = pos[k];
        }
        return result;
    }
};

// 226 / 226 test cases passed.
// Status: Accepted
// Runtime: 12 ms
