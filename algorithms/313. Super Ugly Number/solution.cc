class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, INT_MAX);
        int m = primes.size();
        vector<int> idx(m);
        ugly[0] = 1;
        for ( int i = 1; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( primes[j] * ugly[idx[j]] <= ugly[i-1] ) {
                    ++idx[j];
                }
                ugly[i] = min(ugly[i], primes[j] * ugly[idx[j]]);
            }
        }
        return ugly[n-1];
    }
};

// 83 / 83 test cases passed.
// Status: Accepted
// Runtime: 43 ms
// beats 45.15 %
