class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // maintain the first index of zero
        int i = 0;
        // maintain the first index of non-zero after i
        int j = 0;
        while ( j < nums.size() ) {
            if ( nums[i] ) {
                i++;
                j++;
            } else if ( nums[j] ) {
                swap(nums[i], nums[j]);
            } else {
                j++;
            }
        }
    }
};
