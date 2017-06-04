class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, INT_MAX);
        ugly[0] = 1;
        vector<int> indices(3, 0);
        vector<int> primes = {2, 3, 5};
        for ( int i = 1; i < n; ++i ) {
            for ( int j = 0; j < 3; ++j ) {
                if ( primes[j] * ugly[indices[j]] <= ugly[i - 1] ) {
                    ++indices[j];
                }
                ugly[i] = min(ugly[i], primes[j] * ugly[indices[j]]);
            }
        }
        return ugly.back();
    }
};
