class Solution {
public:
    string convertToTitle(int n) {
        string title;
        while ( n > 0 ) {
            --n;
            title = char(n % 26 + 'A') + title;
            n /= 26;
        }
        return title;
    }
};
