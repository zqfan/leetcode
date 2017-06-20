class Solution {
public:
    int smallestFactorization(int a) {
        if ( a < 10 )
            return a;
        long b = 0;
        for ( int i = 0; i < 11 && a != 1; ++i ) {
            for ( int d = 9; d > 1; --d ) {
                if ( a % d == 0 ) {
                    b += pow(10, i) * d;
                    a /= d;
                    break;
                }
            }
        }
        return ( b > INT_MAX || a != 1 ) ? 0 : b;
    }
};
