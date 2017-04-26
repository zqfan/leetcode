class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while ( l < r ) {
            int m = l + (r - l) / 2, count = 0;
            for ( int i = 0, j = n - 1; i < n; ++i ) {
                while ( j >= 0 && matrix[i][j] > m ) {
                    --j;
                }
                count += j + 1;
            }
            l = count < k ? m + 1 : l;
            r = count < k ? r : m;
        }
        return l;
    }
};

// 85 / 85 test cases passed.
// Status: Accepted
// Runtime: 43 ms
// beats 72.63 %
