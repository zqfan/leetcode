class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        for ( int i = 0, x = 1; i < n; ++i ) {
            result[i] = x;
            if ( x * 10 <= n ) {
                x *= 10;
            } else if ( x < n && x % 10 < 9 ) {
                ++x;
            } else {
                x = x / 10 + 1;
                while ( x % 10 == 0 ) {
                    x /= 10;
                }
            }
        }
        return result;
    }
};

// 26 / 26 test cases passed.
// Status: Accepted
// Runtime: 155 ms
// beats 70.02 %
