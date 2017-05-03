class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        bt(0, nums, path, result);
        return result;
    }

    void bt(int start, vector<int> & nums, vector<int> & path, vector<vector<int>> & result) {
        result.push_back(path);
        for ( int i = start; i < nums.size(); ++i ) {
            path.push_back(nums[i]);
            bt(i + 1, nums, path, result);
            path.pop_back();
        }
    }
};
