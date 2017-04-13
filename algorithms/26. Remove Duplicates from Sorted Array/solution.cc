class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() < 2 ) {
            return nums.size();
        }
        int i = 0;
        for ( int n : nums ) {
            if ( n != nums[i] ) {
                nums[++i] = n;
            }
        }
        return i + 1;
    }
};
