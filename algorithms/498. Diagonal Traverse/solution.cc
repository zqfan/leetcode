class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if ( matrix.size() <= 0 ) {
            return {};
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<int> result(n * m);
        for ( int i = 0, d = 1, r = 0, c = 0; i < result.size(); ++i ) {
            result[i] = matrix[r][c];
            r -= d;
            c += d;
            if ( r >= n ) {
                r = n - 1;
                c += 2;
                d = -d;
            }
            // the if order matters, consider left top case
            if ( c >= m ) {
                r += 2;
                c = m - 1;
                d = -d;
            }
            if ( r < 0 ) {
                r = 0;
                d = -d;
            }
            if ( c < 0 ) {
                c = 0;
                d = -d;
            }
        }
        return result;
    }
};
