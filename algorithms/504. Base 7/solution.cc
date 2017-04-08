class Solution {
public:
    string convertToBase7(int num) {
        if ( num < 0 ) {
            return "-" + convertToBase7(-num);
        }
        string result = "";
        while ( num ) {
            result = to_string(num % 7) + result;
            num /= 7;
        }
        return result == "" ? "0" : result;
    }
};

// 241 / 241 test cases passed.
// Status: Accepted
// Runtime: 3 ms
