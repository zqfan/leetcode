class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        for ( int i = 0; i < findNums.size(); i++ ) {
            int j = 0;
            while ( j < nums.size() && nums[j] != findNums[i] ) {
                j++;
            }
            while ( j < nums.size() && nums[j] <= findNums[i] ) {
                j++;
            }
            if ( j == nums.size() ) {
                result.push_back(-1);
            } else {
                result.push_back(nums[j]);
            }
        }
        return result;
    }
};
