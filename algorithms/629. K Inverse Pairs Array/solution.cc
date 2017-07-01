class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        vector<int> before(k + 1), after(k + 1);
        before[0] = after[0] = 1;
        for ( int i = 1; i <= n; ++i ) {
            after.swap(before);
            for ( int j = 1, l = min(i * (i - 1) / 2, k); j <= l; ++j ) {
                after[j] = after[j-1] + before[j];
                if ( j >= i )
                    after[j] -= before[j-i];
                if ( after[j] < 0 )
                    after[j] += MOD;
                after[j] %= MOD;
            }
        }
        return after[k];
    }
};

// 80 / 80 test cases passed.
// Status: Accepted
// Runtime: 16 ms
// beats 91.82 %
