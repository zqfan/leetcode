class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                if ( !grid[i][j] ) {
                    continue;
                }
                perimeter += 4;
                if ( 0 <= i - 1 && grid[i-1][j] ) {
                    perimeter--;
                }
                if ( j + 1 < m && grid[i][j+1] ) {
                    perimeter--;
                }
                if ( i + 1 < n && grid[i+1][j] ) {
                    perimeter --;
                }
                if ( 0 <= j - 1 && grid[i][j-1] ) {
                    perimeter--;
                }
            }
        }
        return perimeter;
    }
};
