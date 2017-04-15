class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> dup(nums.begin(), nums.end());
        for ( int i = 0, n = nums.size(); i < n; ++i ) {
            // this odd mod is in case i + k overflow, like k = INT_MAX
            nums[(i + k % n) % n] = dup[i];
        }
    }
};
