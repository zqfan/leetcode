class Solution {
public:
    bool splitArray(vector<int>& nums) {
        vector<int> sum = { 0 };
        int n = nums.size();
        for ( int i = 0; i < n; i++ ) {
            sum.push_back(sum.back() + nums[i]);
        }
        int i, j, k;
        set<int> visited;
        for ( j = 3; j < n - 3; j++ ) {
            visited.clear();
            for ( i = 1; i < j - 1; i++ ) {
                if ( sum[i] == sum[j] - sum[i+1] ) {
                    visited.insert(sum[i]);
                }
            }
            for ( k = j + 2; k < n - 1; k++ ) {
                int s1 = sum[k] - sum[j+1];
                int s2 = sum[n] - sum[k+1];
                if ( s1 == s2 && visited.find(s1) != visited.end() ) {
                    return true;
                }
            }
        }
        return false;
    }
};
