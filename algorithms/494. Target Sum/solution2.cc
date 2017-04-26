class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ways = 0;
        dfs(0, S, ways, nums);
        return ways;
    }

    void dfs(int i, int s, int & ways, vector<int> & nums) {
        if ( i == nums.size() ) {
            if ( s == 0 ) {
                ++ways;
            }
            return;
        }
        dfs(i + 1, s - nums[i], ways, nums);
        dfs(i + 1, s + nums[i], ways, nums);
    }
};

// 139 / 139 test cases passed.
// Status: Accepted
// Runtime: 499 ms
// beats 21.13 %
