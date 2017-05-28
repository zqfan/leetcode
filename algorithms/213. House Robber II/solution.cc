class Solution {
public:
    int rob(vector<int>& nums) {
        if ( nums.size() > 1 ) {
            return max(robrange(nums, 0, nums.size() - 1), robrange(nums, 1, nums.size()));
        } else {
            return nums.size() ? nums[0] : 0;
        }
    }

    int robrange(vector<int> & nums, int start, int end) {
        int p1 = 0, p2 = 0, tmp;
        for ( int i = start; i < end; ++i ) {
            tmp = p2;
            p2 = max(p1 + nums[i], p2);
            p1 = tmp;
        }
        return p2;
    }
};
