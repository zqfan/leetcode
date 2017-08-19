class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int k = 0;
        for ( int i = 1; i < nums.size(); ++i ) {
            if ( nums[i] - nums[i-1] > 1 ) {
                if ( ! possible(nums, k, i) )
                    return false;
                k = i;
            }
        }
        return possible(nums, k, nums.size());
    }

    bool possible(vector<int> & nums, int start, int end) {
        int l1 = 0, l2 = 0, pre = 0, cnt = 1;
        for ( int i = start + 1; i <= end; ++i ) {
            if ( i < end && nums[i] == nums[i-1] ) {
                ++cnt;
            } else {
                if ( cnt < l1 + l2 )
                    return false;
                l2 = l1;
                l1 = max(0, cnt - pre);
                pre = cnt;
                cnt = 1;
            }
        }
        return l1 == 0 && l2 == 0;
    }
};

// 180 / 180 test cases passed.
// Status: Accepted
// Runtime: 89 ms
// beats 88.89 %
