class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum = 0, ksum = 0;
        for ( int i = 0; i < k; ++i )
            maxsum = ksum = ksum + nums[i];
        for ( int i = k; i < nums.size(); ++i ) {
            ksum += nums[i] - nums[i-k];
            maxsum = max(maxsum, ksum);
        }
        return maxsum / k;
    }
};
