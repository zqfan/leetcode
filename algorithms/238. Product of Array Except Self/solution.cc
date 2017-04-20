class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        for ( int i = 1; i < nums.size(); ++i ) {
            result[i] = result[i-1] * nums[i-1];
        }
        for ( int i = nums.size() - 2, p = 1; i >= 0; --i ) {
            p *= nums[i+1];
            result[i] *= p;
        }
        return result;
    }
};
