class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }

    void dfs(vector<int>& nums, int start, vector<vector<int>> & result) {
        if ( start >= nums.size() ) {
            result.push_back(nums);
        }
        for ( int i = start; i < nums.size(); ++i ) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};
