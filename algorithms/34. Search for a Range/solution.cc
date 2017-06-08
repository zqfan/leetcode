class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(nums.begin(), nums.end(), target);
        if ( range.first == range.second ) return {-1, -1};
        return {range.first - nums.begin(), range.second - nums.begin() - 1};
    }
};
