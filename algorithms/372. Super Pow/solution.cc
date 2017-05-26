class Solution {
    const int MOD = 1337;
    int modpow(int a, int b) {
        int r = 1;
        for ( int i = 0; i < b; ++i ) {
            r = (r * a) % MOD;
        }
        return r;
    }
public:
    int superPow(int a, vector<int>& b) {
        int r = 1;
        a %= MOD;
        for ( int d : b ) {
            r = modpow(r, 10) * modpow(a, d) % MOD;
        }
        return r;
    }
};

// 54 / 54 test cases passed.
// Status: Accepted
// Runtime: 13 ms
// beats 45.45 %
