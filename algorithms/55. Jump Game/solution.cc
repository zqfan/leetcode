class Solution {
public:
    bool canJump(vector<int>& nums) {
        int final = nums.size() - 1;
        for ( int i = 0, j = 0; i <= j; ++i ) {
            j = max(j, nums[i] + i);
            if ( j >= final )
                return true;
        }
        return false;
    }
};
