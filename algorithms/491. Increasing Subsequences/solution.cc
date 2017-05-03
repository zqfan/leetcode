class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        bt(0, nums, path, result);
        return result;
    }

    void bt(int start, vector<int> & nums, vector<int> & path, vector<vector<int>> & result) {
        if ( path.size() > 1 ) {
            result.push_back(path);
        }
        set<int> visited;
        for ( int i = start; i < nums.size(); ++i ) {
            if ( visited.find(nums[i]) != visited.end() ) {
                continue;
            }
            if ( path.empty() || nums[i] >= path.back() ) {
                path.push_back(nums[i]);
                bt(i + 1, nums, path, result);
                path.pop_back();
                visited.insert(nums[i]);
            }
        }
    }
};
