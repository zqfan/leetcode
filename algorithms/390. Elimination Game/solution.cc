class Solution {
public:
    int lastRemaining(int n) {
        int last = 1, step = 1, l2r = 1;
        while ( n > 1 ) {
            if ( l2r || n % 2 ) {
                last += step;
            }
            n /= 2;
            step *= 2;
            l2r = 1 - l2r;
        }
        return last;
    }
};
