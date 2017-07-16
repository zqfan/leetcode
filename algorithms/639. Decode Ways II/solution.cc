class Solution {
public:
    int numDecodings(string s) {
        long e0 = 1, e1 = 0, e2 = 0, f0, f1, f2;
        for ( char c : s ) {
            if ( '*' == c ) {
                f0 = 9 * e0 + 9 * e1 + 6 * e2;
                f1 = f2 = e0;
            } else {
                f0 = int(c > '0') * e0 + e1 + int(c < '7') * e2;
                f1 = '1' == c ? e0 : 0;
                f2 = '2' == c ? e0 : 0;
            }
            e0 = f0 % 1000000007;
            e1 = f1;
            e2 = f2;
        }
        return int(e0);
    }
};

// 194 / 194 test cases passed.
// Status: Accepted
// Runtime: 62 ms
// beats 87.82 %
