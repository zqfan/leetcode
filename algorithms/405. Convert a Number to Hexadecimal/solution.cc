class Solution {
public:
    string toHex(int num) {
        if ( 0 == num ) {
            return "0";
        }
        string letters = "0123456789abcdef";
        string result;
        // handle negative shift;
        unsigned int n = num;
        while ( n ) {
            result.push_back(letters[n & 0xf]);
            n >>= 4;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// 100 / 100 test cases passed.
// Status: Accepted
// Runtime: 0 ms
// beats 94.42%
