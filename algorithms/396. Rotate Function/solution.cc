class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size(), f = 0, m = INT_MIN;
        int sum = accumulate(A.begin(), A.end(), 0);
        for ( int i = 0; i < n; ++i ) {
            f += i * A[i];
        }
        for ( int i = n - 1; i >= 0; --i ) {
            m = max(m, f);
            f += sum - n * A[i];
        }
        return n ? m : 0;
    }
};
