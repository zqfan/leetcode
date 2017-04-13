class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p(numRows);
        for ( int i = 0; i < numRows; ++i ) {
            p[i].resize(i + 1);
            p[i][0] = p[i][i] = 1;
            for ( int j = 1; j < i; ++j ) {
                p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
            }
        }
        return p;
    }
};
