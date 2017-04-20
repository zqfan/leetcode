class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cur = 0, total = 0;
        for ( int i = 2; i < A.size(); ++i ) {
            if ( A[i] - A[i-1] == A[i-1] - A[i-2] ) {
                ++cur;
                total += cur;
            } else {
                cur = 0;
            }
        }
        return total;
    }
};
