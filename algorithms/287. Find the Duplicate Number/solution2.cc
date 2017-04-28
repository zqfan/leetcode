class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1, m, count;
        while ( l < r ) {
            m = l + (r - l) / 2;
            count = 0;
            for ( int n : nums ) {
                if ( n <= m ) {
                    ++count;
                }
            }
            if ( count <= m ) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
