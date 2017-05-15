class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 1, end = 0, mini = INT_MAX, maxi = INT_MIN;
        for ( int i = 0; i < nums.size(); ++i ) {
            maxi = max(nums[i], maxi);
            if ( nums[i] < maxi ) {
                end = i;
            }
        }
        for ( int i = nums.size() - 1; i >= 0; --i ) {
            mini = min(nums[i], mini);
            if ( nums[i] > mini ) {
                start = i;
            }
        }
        return end - start + 1;
    }
};
