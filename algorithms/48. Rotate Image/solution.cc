class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // @ shichaotan
        reverse(matrix.begin(), matrix.end());
        for ( int i = 0, n = matrix.size(); i < n; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
