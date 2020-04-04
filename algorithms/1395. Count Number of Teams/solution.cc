class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            int less[2] = {}, bigger[2] = {};
            for (int j = 0; j < n; ++j) {
                if (rating[j] > rating[i])
                    ++less[i < j];
                else if (rating[j] < rating[i])
                    ++bigger[i < j];
            }
            cnt += less[0] * bigger[1] + less[1] * bigger[0];
        }
        return cnt;
    }
};

// Runtime: 60 ms, faster than 84.74% of Python online submissions for Count Number of Teams.
// Memory Usage: 12.6 MB, less than 100.00% of Python online submissions for Count Number of Teams.
