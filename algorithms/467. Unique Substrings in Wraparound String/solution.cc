class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26);
        for ( int i = 0, j = 0, n = p.size(); i < n; ++i ) {
            if ( i && p[i] - p[i-1] != 1 && p[i] - p[i-1] != -25 ) {
                j = i;
            }
            count[p[i] - 'a'] = max(count[p[i] - 'a'], i - j + 1);
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};
