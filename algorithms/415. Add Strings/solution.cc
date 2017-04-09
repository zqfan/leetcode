class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<char> result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while ( i >= 0 || j >= 0 || carry ) {
            if ( i >= 0 ) {
                carry += num1[i] - '0';
                --i;
            }
            if ( j >= 0 ) {
                carry += num2[j] - '0';
                --j;
            }
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(result.begin(), result.end());
        return string (result.begin(), result.end());
    }
};

// 315 / 315 test cases passed.
// Status: Accepted
// Runtime: 6 ms
// beats 85.96%
