class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(0, nums, path, res);
        return res;
    }

    void dfs(int start, vector<int> & nums, vector<int> & path, vector<vector<int>> & res) {
        res.push_back(path);
        for ( int i = start; i < nums.size(); ++i ) {
            if ( i == start || nums[i] != nums[i-1] ) {
                path.push_back(nums[i]);
                dfs(i + 1, nums, path, res);
                path.pop_back();
            }
        }
    }
};
