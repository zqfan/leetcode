class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                int count = 0;
                for ( int x = i-1; x <= i+1; ++x ) {
                    for ( int y = j-1; y <= j+1; ++y ) {
                        if ( 0 <= x && x < m && 0 <= y && y < n ) {
                            count += board[x][y] & 1;
                        }
                    }
                }
                if ( count == 3 || count - board[i][j] == 3 ) {
                    board[i][j] |= 2;
                }
            }
        }
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                board[i][j] >>= 1;
            }
        }
    }
};
