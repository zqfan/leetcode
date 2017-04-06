class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for ( int i = 0; i < nums.size(); i++ ) {
            int next = nums[i] - 1, cur = i;
            while ( nums[next] ) {
                cur = next;
                next = nums[next] - 1;
                nums[cur] = 0;
            }
        }
        vector<int> result;
        for ( int i = 0; i < nums.size(); i++ ) {
            if ( nums[i] ) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
