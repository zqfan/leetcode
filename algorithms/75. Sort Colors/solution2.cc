class Solution {
public:
    void sortColors(vector<int>& nums) {
        int e = 0, u = 0, g = nums.size();
        while ( u < g ) {
            if ( nums[u] == 0 ) {
                swap(nums[e++], nums[u++]);
            } else if ( nums[u] == 2 ) {
                swap(nums[u], nums[--g]);
            } else {
                ++u;
            }
        }
    }
};
