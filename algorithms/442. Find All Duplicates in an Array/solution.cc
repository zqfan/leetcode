class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> dup;
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( nums[abs(nums[i]) - 1] < 0 ) {
                dup.push_back(abs(nums[i]));
            }
            nums[abs(nums[i]) - 1] *= -1;
        }
        return dup;
    }
};
