class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // maintain i as last pos of non val
        int i = 0;
        for ( int j = 0; j < nums.size(); ++j ) {
            if ( nums[j] != val ) {
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
