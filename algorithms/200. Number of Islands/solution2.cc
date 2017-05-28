class Solution {
    vector<int> id;
    int count;
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, l = m * n;
        int dx[2] = {0, 1}, dy[2] = {1, 0};
        id.resize(l);
        count = 0;
        for ( int i = 0; i < l; ++i ) id[i] = i;
        for ( int i = 0; i < m; ++i )
            for ( int j = 0; j < n; ++j )
                if ( '1' == grid[i][j] ) {
                    ++count;
                    for ( int k = 0; k < 2; ++k ) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if ( x < m && y < n && '1' == grid[x][y] ) {
                            merge(i * n + j, x * n + y);
                        }
                    }
                }
        return count;
    }

    int find(int p) {
        while ( p != id[p] ) {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }

    void merge(int p, int q) {
        p = find(p);
        q = find(q);
        if ( p != q ) {
            id[p] = q;
            --count;
        }
    }
};
