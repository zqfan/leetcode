class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> best(n, 1);
        for ( int i = 0; i < n; ++i ) {
            for ( int j = 0; j < i; ++j ) {
                if ( nums[i] > nums[j] ) {
                    best[i] = max(best[i], best[j] + 1);
                }
            }
        }
        return nums.empty() ? 0 : * max_element(best.begin(), best.end());
    }
};
