class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> last;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( last.find(nums[i]) != last.end() && i - last[nums[i]] <= k ) {
                return true;
            }
            last[nums[i]] = i;
        }
        return false;
    }
};
