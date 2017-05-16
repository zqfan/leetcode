class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> comb;
        vector<vector<int>> result;
        dfs(0, target, candidates, comb, result);
        return result;
    }

    void dfs(int start, int target, vector<int> & nums, vector<int> & comb, vector<vector<int>> & result) {
        if ( target == 0 ) {
            result.push_back(comb);
            return;
        }
        for ( int i = start; i < nums.size() && nums[i] <= target; ++i ) {
            comb.push_back(nums[i]);
            dfs(i, target - nums[i], nums, comb, result);
            comb.pop_back();
        }
    }
};
