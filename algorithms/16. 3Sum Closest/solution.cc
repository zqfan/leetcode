class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        long long result = nums[0] + nums[1] + nums[2], tmp;
        int n = nums.size();
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        for ( int i, j = 0, k; j < n; ++j ) {
            i = 0;
            k = n - 1;
            while ( i < j && j < k ) {
                tmp = snums[i] + snums[j] + snums[k];
                if ( tmp > target ) {
                    --k;
                } else if ( tmp < target ) {
                    ++i;
                } else {
                    return target;
                }
                if ( abs(tmp - target) < abs(result - target) ) {
                    result = tmp;
                }
            }
        }
        return result;
    }
};
