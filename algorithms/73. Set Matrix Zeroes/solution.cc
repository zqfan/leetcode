class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, col0 = 1;
        for ( int i = 0; i < m; ++i ) {
            if ( 0 == matrix[i][0] ) {
                col0 = 0;
            }
            for ( int j = 1; j < n; ++j ) {
                if ( 0 == matrix[i][j] ) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for ( int i = m - 1; i >= 0; --i ) {
            for ( int j = 1; j < n; ++j ) {
                if ( 0 == matrix[i][0] || 0 == matrix[0][j] ) {
                    matrix[i][j] = 0;
                }
            }
            if ( 0 == col0 ) {
                matrix[i][0] = 0;
            }
        }
    }
};
