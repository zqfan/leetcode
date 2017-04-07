class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        string top3 [] = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        vector<string> result;
        for ( int n : nums ) {
            int idx = lower_bound(sorted.begin(), sorted.end(), n) - sorted.begin();
            // sort order is increasing, but we need decreasing
            idx = nums.size() - 1 - idx;
            if ( idx < 3 ) {
                result.push_back(top3[idx]);
            } else {
                result.push_back(to_string(idx + 1));
            }
        }
        return result;
    }
};
