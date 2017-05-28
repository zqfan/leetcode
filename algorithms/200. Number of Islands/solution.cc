class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for ( int i = 0; i < m; ++i ) {
            for ( int j = 0; j < n; ++j ) {
                if ( '1' == grid[i][j] && ! visited[i][j] ) {
                    dfs(i, j, grid, visited);
                    ++islands;
                }
            }
        }
        return islands;
    }

    void dfs(int i, int j, vector<vector<char>> & grid, vector<vector<bool>> & visited ) {
        if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ) {
            return;
        }
        if ( visited[i][j] || grid[i][j] == '0' ) {
            return;
        }
        visited[i][j] = true;
        dfs(i - 1, j, grid, visited);
        dfs(i, j + 1, grid, visited);
        dfs(i + 1, j, grid, visited);
        dfs(i, j - 1, grid, visited);
    }
};
