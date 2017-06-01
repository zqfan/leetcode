class Solution {
    int m, n, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if ( matrix.empty() ) return result;
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for ( int i = 0; i < m; ++i ) {
            dfs(i, 0, matrix, visited, 1);
            dfs(i, n-1, matrix, visited, 2);
        }
        for ( int j = 0; j < n; ++j ) {
            dfs(0, j, matrix, visited, 1);
            dfs(m-1, j, matrix, visited, 2);
        }
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
                if ( 3 == visited[i][j] ) result.push_back(make_pair(i, j));
        return result;
    }

    void dfs(int i, int j, vector<vector<int>> & matrix, vector<vector<int>> & visited, int mask) {
        visited[i][j] |= mask;
        for ( int d = 0, x, y; d < 4; ++d ) {
            x = i + dx[d];
            y = j + dy[d];
            if ( x < 0 || x >= m || y < 0 || y >= n ) continue;
            if ( matrix[i][j] > matrix[x][y] || (visited[x][y] & mask) ) continue;
            dfs(x, y, matrix, visited, mask);
        }
    }
};
