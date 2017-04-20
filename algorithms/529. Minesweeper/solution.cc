class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if ( 'M' == board[click[0]][click[1]] ) {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        int mines = 0, n = board.size(), m = board[0].size();
        vector<vector<int>> candidates;
        for ( int i = -1; i <= 1; ++i ) {
            for ( int j = -1; j <= 1; ++j ) {
                int x = click[0] + i;
                int y = click[1] + j;
                if ( 0 <= x && x < n && 0 <= y && y < m ) {
                    if ( 'M' == board[x][y] ) {
                        ++mines;
                    } else if ( 'E' == board[x][y] ) {
                        candidates.push_back(vector<int> ({x, y}));
                    }
                }
            }
        }
        if ( mines > 0 ) {
            board[click[0]][click[1]] = char(mines + '0');
        } else {
            board[click[0]][click[1]] = 'B';
            for ( auto & c : candidates ) {
                updateBoard(board, c);
            }
        }
        return board;
    }
};
