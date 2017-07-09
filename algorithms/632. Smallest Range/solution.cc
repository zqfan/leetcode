class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // @tmt514
        vector<int> pos(nums.size());
        set<pair<int, int>> q;
        for ( int i = 0, n = nums.size(); i < n; ++i )
            q.emplace(make_pair(nums[i][pos[i]++], i));
        int left = q.begin()->first, right = q.rbegin()->first;
        while ( true ) {
            int val = q.begin()->first, i = q.begin()->second;
            if ( val == nums[i].back() )
                break;
            q.erase(q.begin());
            q.emplace(make_pair(nums[i][pos[i]++], i));
            int l = q.begin()->first, r = q.rbegin()->first;
            if ( right - left > r - l ) {
                left = l;
                right = r;
            }
        }
        return {left, right};
    }
};

// 86 / 86 test cases passed.
// Status: Accepted
// Runtime: 46 ms
// beats 67.50 %
