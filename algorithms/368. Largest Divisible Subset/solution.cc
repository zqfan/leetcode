class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxlen = 0, lastidx = -1;
        vector<int> count(n), pre(n);
        sort(nums.begin(), nums.end());
        for ( int i = 0; i < n; ++i ) {
            count[i] = 1;
            pre[i] = -1;
            for ( int j = 0; j < i; ++j ) {
                if ( nums[i] % nums[j] == 0 && count[j] + 1 > count[i] ) {
                    count[i] = count[j] + 1;
                    pre[i] = j;
                }
            }
            if ( count[i] > maxlen ) {
                maxlen = count[i];
                lastidx = i;
            }
        }
        vector<int> result;
        while ( lastidx != -1 ) {
            result.push_back(nums[lastidx]);
            lastidx = pre[lastidx];
        }
        return result;
    }
};
