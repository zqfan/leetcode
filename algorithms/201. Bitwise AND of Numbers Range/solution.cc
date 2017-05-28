class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int d = n - m, l, res = n & m;
        for ( int i = 0; i < 31; ++i ) {
            l = 1 << i;
            if ( d >= l ) res &= ~l;
        }
        return res;
    }
};
