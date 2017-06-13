class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int m = INT_MAX, n = nums.size(), sum = 0;
        for ( int i = 0, j = 0; j < n; ++j ) {
            sum += nums[j];
            while ( sum >= s + nums[i] )
                sum -= nums[i++];
            if ( sum >= s )
                m = min(m, j - i + 1);
        }
        return m == INT_MAX ? 0 : m;
    }
};
