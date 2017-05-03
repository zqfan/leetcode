class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX, m2 = INT_MAX;
        for ( int n : nums ) {
            if ( m2 < n ) return true;
            m1 = min(m1, n);
            if ( m1 < n && n < m2 ) m2 = n;
        }
        return false;
    }
};
