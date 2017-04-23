class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int n = M.size(), m = n == 0 ? 0 : M[0].size(), ll = 0;
        vector<int> pre(4 * m + 8), cur(4 * m + 8);
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < m; ++j ) {
                if ( M[i][j] ) {
                    cur[4 * j + 4] = cur[4 * j] + 1; // left
                    cur[4 * j + 5] = pre[4 * j + 1] + 1; // left top
                    cur[4 * j + 6] = pre[4 * j + 6] + 1; // top
                    cur[4 * j + 7] = pre[4 * j + 11] + 1; // right top
                }
            }
            ll = max(ll, *max_element(cur.begin(), cur.end()));
            pre = cur;
            fill(cur.begin(), cur.end(), 0);
        }
        return ll;
    }
};
