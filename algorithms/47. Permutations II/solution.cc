class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        dfs(0, snums, result);
        return result;
    }

    void dfs(int start, vector<int> nums, vector<vector<int>> & result) {
        if ( start == nums.size() ) {
            result.push_back(nums);
        }
        for ( int i = start; i < nums.size(); ++i ) {
            if ( i == start || nums[i] != nums[start] ) {
                swap(nums[i], nums[start]);
                dfs(start + 1, nums, result);
            }
        }
    }
};
