class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int> (n));
        int left = 0, right = n - 1, up = 0, down = n - 1;
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };
        int i = 0, j = 0, nn = n * n, count = 0, d = 0;
        while ( count < nn ) {
            m[i][j] = ++count;
            if ( j + dy[d] > right ) {
                d = (d + 1) % 4;
                ++up;
            }
            if ( i + dx[d] > down ) {
                d = (d + 1) % 4;
                --right;
            }
            if ( j + dy[d] < left ) {
                d = (d + 1) % 4;
                --down;
            }
            if ( i + dx[d] < up ) {
                d = (d + 1) % 4;
                ++left;
            }
            i += dx[d];
            j += dy[d];
        }
        return m;
    }
};
