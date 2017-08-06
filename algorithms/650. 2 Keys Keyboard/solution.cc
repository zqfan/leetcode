class Solution {
public:
    int minSteps(int n) {
        int s = 0;
        for ( int i = 2; i <= n; ++i )
            while ( n % i == 0 ) {
                s += i;
                n /= i;
            }
        return s;
    }
};

// 126 / 126 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// beats 62.38 %
