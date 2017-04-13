class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mem;
        int n = nums.size();
        for ( int i = 0; i < n; ++i ) {
            if ( mem.find(nums[i]) != mem.end() ) {
                return {mem[nums[i]], i};
            }
            mem[target - nums[i]] = i;
        }
    }
};
