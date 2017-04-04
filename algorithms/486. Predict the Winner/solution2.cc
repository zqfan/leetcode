class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        vector<int> sum(n + 1);
        for ( int i = 0; i < n; i++ ) {
            sum[i+1] = sum[i] + nums[i];
        }
        return 2 * dfs(0, n-1, nums, mem, sum) >= sum[n];
    }

    int dfs(int i, int j, vector<int> & nums, vector<vector<int>> & mem, vector<int> & sum) {
        if ( i > j ) {
            return 0;
        }
        if ( -1 == mem[i][j] ) {
            int sij = sum[j+1] - sum[i];
            int left = dfs(i, j-1, nums, mem, sum);
            int right = dfs(i+1, j, nums, mem, sum);
            mem[i][j] = sij - min(left, right);
        }
        return mem[i][j];
    }
};
