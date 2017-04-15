class Solution {
public:
    int countPrimes(int n) {
        if ( n < 2 ) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        int sqrtn = int(sqrt(n));
        for ( int i = 2; i <= sqrtn; ++i ) {
            if ( isPrime[i] ) {
                for ( int j = i * i; j < n; j += i ) {
                    isPrime[j] = false;
                }
            }
        }
        return count(isPrime.begin(), isPrime.end(), true);
    }
};

// 20 / 20 test cases passed.
// Status: Accepted
// Runtime: 46 ms
// beats 43.82%
