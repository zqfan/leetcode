class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for ( int i = 0; i < nums.size(); i++ ) {
            int next = abs(nums[i]) - 1;
            if ( nums[next] > 0 ) {
                nums[next] = -nums[next];
            }
        }
        vector<int> result;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] > 0 ) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
