class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool r[9][9] = {0}, c[9][9] = {0}, g[3][3][9] = {0};
        for ( int i = 0; i < 9; ++i ) {
            for ( int j = 0; j < 9; ++j ) {
                if ( board[i][j] != '.' ) {
                    int n = board[i][j] - '1';
                    if ( r[i][n] || c[j][n] || g[i/3][j/3][n] ) {
                        return false;
                    }
                    r[i][n] = c[j][n] = g[i/3][j/3][n] = true;
                }
            }
        }
        return true;
    }
};
