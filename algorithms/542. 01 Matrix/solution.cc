class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( 0 == matrix[i][j] ) {
                    dis[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        while ( q.size() ) {
            auto p = q.front();
            q.pop();
            for ( int d = 0, x, y; d < 4; ++d ) {
                x = p.first + dx[d];
                y = p.second + dy[d];
                if ( 0 <= x && x < m && 0 <= y && y < n && INT_MAX == dis[x][y] ) {
                    dis[x][y] = dis[p.first][p.second] + 1;
                    q.push(make_pair(x, y));
                }
            }
        }
        return dis;
    }
};
