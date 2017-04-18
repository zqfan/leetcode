class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if ( nums.size() == 1 ) {
            return to_string(nums[0]);
        }
        string result = to_string(nums[1]);
        for ( int i = 2; i < nums.size(); ++i ) {
            result += "/" + to_string(nums[i]);
        }
        if ( nums.size() > 2 ) {
            return to_string(nums[0]) + "/(" + result + ")";
        } else {
            return to_string(nums[0]) + "/" + result;
        }
    }
};
