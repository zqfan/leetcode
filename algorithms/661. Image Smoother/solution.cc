class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> r(m, vector<int> (n));
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                int cnt = 0;
                for ( int ni = i - 1; ni < i + 2; ++ni ) {
                    for ( int nj = j - 1; nj < j + 2; ++nj ) {
                        if ( 0 <= ni && ni < m && 0 <= nj && nj < n ) {
                            ++cnt;
                            r[i][j] += M[ni][nj];
                        }
                    }
                }
                r[i][j] /= cnt;
            }
        }
        return r;
    }
};

// 202 / 202 test cases passed.
// Status: Accepted
// Runtime: 172 ms
