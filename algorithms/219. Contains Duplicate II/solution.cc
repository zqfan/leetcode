class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for ( int i = 0; i < nums.size() && k > 0; ++i ) {
            if ( i > k ) {
                window.erase(nums[i - k - 1]);
            }
            if ( ! window.insert(nums[i]).second ) {
                return true;
            }
        }
        return false;
    }
};
