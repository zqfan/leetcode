class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int result = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        for ( int c1 = 0; c1 < m; c1++ ) {
            vector<int> sum(n, 0);
            for ( int c2 = c1; c2 < m; c2++ ) {
                for ( int r = 0; r < n; r++ ) {
                    sum[r] += matrix[r][c2];
                }
                int maximum = INT_MIN;
                int cur = 0;
                set<int> visited = { 0 };
                for ( int i = 0; i < n; i++ ) {
                    cur += sum[i];
                    set<int>::iterator it = visited.lower_bound(cur - k);
                    if ( visited.end() != it ) {
                        maximum = max(maximum, cur - *it);
                    }
                    visited.insert(cur);
                }
                result = max(result, maximum);
            }
        }
        return result;
    }
};
