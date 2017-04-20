class Solution {
public:
    int minMoves2(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        int moves = 0, median = nums[nums.size() / 2];
        for ( int i = 0; i < nums.size(); ++i ) {
            moves += abs(nums[i] - median);
        }
        return moves;
    }
};
