class Solution {
public:
    int numSquares(int n) {
        if ( isSquare(n) ) {
            return 1;
        }
        while ( (n & 3) == 0 ) {
            n >>= 2;
        }
        if ( n % 8 == 7 ) {
            return 4;
        }
        for ( int i = 1; i * i < n; ++i ) {
            if ( isSquare(n - i * i) ) {
                return 2;
            }
        }
        return 3;
    }

    bool isSquare(int n) {
        int sqrtn = sqrt(n);
        return sqrtn * sqrtn == n;
    }
};
