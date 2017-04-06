class Solution {
public:
    char findTheDifference(string s, string t) {
        char d = 0;
        for ( char c : s ) {
            d ^= c;
        }
        for ( char c : t ) {
            d ^= c;
        }
        return d;
    }
};
