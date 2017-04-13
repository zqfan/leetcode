class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        while ( n > 0 ) {
            n /= 5;
            zeroes += n;
        }
        return zeroes;
    }
};
