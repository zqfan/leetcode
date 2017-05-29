class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for ( auto & p : ops ) {
            m = min(m, p[0]);
            n = min(n, p[1]);
        }
        return m * n;
    }
};
