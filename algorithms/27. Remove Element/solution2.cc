class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // maintain i as first pos of val
        int i = 0;
        // maintain j as last pos of non val
        int j = nums.size() - 1;
        while ( i <= j ) {
            if ( nums[i] != val ) {
                ++i;
            } else if ( nums[j] == val ) {
                --j;
            } else {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return i;
    }
};
