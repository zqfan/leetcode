class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                sum[i+1][j+1] = matrix[i][j] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
            }
        }
        int min = INT_MIN;
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < m; j++ ) {
                for ( int x = i; x < n; x++ ) {
                    for ( int y = j; y < m; y++ ) {
                        int s = sum[x+1][y+1] - sum[i][y+1] - sum[x+1][j] + sum[i][j];
                        if ( s <= k && s > min) {
                            min = s;
                        }
                    }
                }
            }
        }
        return min;
    }
};
