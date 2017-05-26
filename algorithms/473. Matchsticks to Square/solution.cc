class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int p = accumulate(nums.begin(), nums.end(), 0);
        if ( p % 4 != 0 ) {
            return false;
        }
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int unused = (1 << nums.size()) - 1;
        return dfs(unused, p / 4, p / 4, 0, nums);
    }

    bool dfs(int unused, int target, int len, int count, vector<int> & nums) {
        if ( 0 == target ) {
            target = len;
            ++count;
        }
        if ( 0 == unused ) {
            return target == len && count == 4;
        }
        if ( count >= 4 ) {
            return false;
        }
        for ( int i = 0; i < nums.size(); ++i ) {
            if ( (1 << i) & unused ) {
                if ( nums[i] > target ) {
                    break;
                }
                unused &= ~(1 << i);
                if (dfs(unused, target - nums[i], len, count, nums) ) {
                    return true;
                }
                unused |= 1 << i;
            }
        }
        return false;
    }
};
