class Solution {
public:
    string decodeString(string s) {
        // @bluedawnstar
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(const string & s, int & i) {
        string result;
        while ( i < s.size() && s[i] != ']' ) {
            if ( isalpha(s[i]) ) {
                result += s[i];
                ++i;
            } else {
                int n = 0;
                while ( isdigit(s[i]) ) {
                    n = n * 10 + s[i] - '0';
                    ++i;
                }
                ++i; // skip [
                string sub = decodeString(s, i);
                ++i; // skip ]
                while ( n-- > 0 ) {
                    result += sub;
                }
            }
        }
        return result;
    }
};
