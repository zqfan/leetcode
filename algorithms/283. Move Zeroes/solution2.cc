class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // maintain the next insert position for non-zero
        int i = 0;
        for ( int n : nums ) {
            if ( n ) {
                nums[i++] = n;
            }
        }
        while ( i < nums.size() ) {
            nums[i++] = 0;
        }
    }
};
