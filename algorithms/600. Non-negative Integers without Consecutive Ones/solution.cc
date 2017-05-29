class Solution {
public:
    int findIntegers(int num) {
        // @ zestypanda
        int f[32] = {1, 2};
        for ( int i = 2; i < 32; ++i ) f[i] = f[i-1] + f[i-2];
        int k = 31, prebit = 0, res = 0;
        while ( --k >= 0 ) {
            if ( num & (1 << k) ) {
                // put this bit to 0
                res += f[k];
                // try to put this bit to 1, if consecutive 1, exit
                if ( prebit ) return res;
                prebit = 1;
            } else {
                prebit = 0;
            }
        }
        return res + 1;
    }
};
