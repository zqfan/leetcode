class Solution {
public:
    int findDerangement(int n) {
        // f(n, 0) = (n - 1) * f(n - 1, 0) + f(n - 1, 1)
        // f(n, 1) = n * f(n - 1, 0)
        long f0, f1 = 1, f2 = 0;
        for ( int i = 3; i <= n; ++i ) {
            f0 = f1;
            f1 = (i - 1) * (f1 + f2) % 1000000007;
            f2 = f0;
        }
        return n < 2 ? 0 : f1;
    }
};
