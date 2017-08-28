class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int dec = 0;
        for ( int i = 1; dec < 2 && i < nums.size(); ++i ) {
            if ( nums[i] < nums[i-1] ) {
                ++dec;
                if ( i == 1 || nums[i-2] <= nums[i] )
                    nums[i-1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return dec < 2;
    }
};

// 325 / 325 test cases passed.
// Status: Accepted
// Runtime: 33 ms
