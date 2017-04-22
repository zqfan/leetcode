class Solution {
public:
    int magicalString(int n) {
        vector<int> s(n);
        for ( int i = 0, j = 0, d = 1; i < n; ++i, ++j ) {
            s[i] = d;
            if ( s[j] == 2 && i + 1 < n) {
                s[++i] = d;
            }
            d = d == 1 ? 2 : 1;
        }
        return count(s.begin(), s.end(), 1);
    }
};
