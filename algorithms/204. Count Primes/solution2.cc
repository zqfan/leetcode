class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        primes.push_back(2);
        for ( int i = 3; i < n; i += 2 ) {
            bool isPrime = true;
            for ( int j = 0; j < primes.size() && primes[j] <= i / primes[j]; ++j ) {
                if ( i % primes[j] == 0 ) {
                    isPrime = false;
                    break;
                }
            }
            if ( isPrime ) {
                primes.push_back(i);
            }
        }
        return n < 3 ? 0 : primes.size();
    }
};

// 20 / 20 test cases passed.
// Status: Accepted
// Runtime: 462 ms
// beats 4.19%
