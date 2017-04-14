class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        string result;
        while ( i >= 0 || j >= 0 || carry ) {
            if ( i >= 0 ) {
                carry += a[i] - '0';
                --i;
            }
            if ( j >= 0 ) {
                carry += b[j] - '0';
                --j;
            }
            result = char('0' + carry % 2) + result;
            carry /= 2;
        }
        return result;
    }
};
