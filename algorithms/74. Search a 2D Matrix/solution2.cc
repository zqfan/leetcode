class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int l = 0, h = m - 1;
        while ( l < h ) {
            int m = (l + h) / 2;
            if ( target > matrix[m].back() ) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        if ( l >= m ) {
            return false;
        }
        auto p = lower_bound(matrix[l].begin(), matrix[l].end(), target);
        return p != matrix[l].end() && *p == target;
    }
};
