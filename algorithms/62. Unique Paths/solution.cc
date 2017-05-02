class Solution {
public:
    int uniquePaths(int m, int n) {
        // total n - 1 + m - 1 steps, we can choose n - 2 right moves
        // Combinations(n+m-2, n-1) = (n+m-2)!/((n-1)!*(m-1)!) 
        double p = 1.0;
        for ( int i = 1; i < m; ++i ) {
            p = p * (n - 1 + i) / i;
        }
        return round(p);
    }
};
