class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size(), K = days[0].size();
        vector<int> best(n, INT_MIN), cur(n);
        best[0] = 0;
        for ( int k = 0; k < K; ++k ) {
            fill(cur.begin(), cur.end(), INT_MIN);
            for ( int i = 0; i < n; ++i ) {
                for ( int j = 0; j < n; ++j ) {
                    if ( flights[i][j] || i == j ) {
                        cur[j] = max(cur[j], best[i] + days[j][k]);
                    }
                }
            }
            best = cur;
        }
        return *max_element(best.begin(), best.end());
    }
};

// 57 / 57 test cases passed.
// Status: Accepted
// Runtime: 149 ms
