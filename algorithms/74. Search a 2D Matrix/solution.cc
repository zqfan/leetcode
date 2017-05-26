class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        int l = 0, r = m * n - 1, mid, num;
        while ( l <= r ) {
            mid = (l + r) / 2;
            num = matrix[mid / n][mid % n];
            if ( target < num ) {
                r = mid - 1;
            } else if ( target > num ) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
