class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bits(32);
        for ( int n : nums ) {
            for ( int i = 0; i < 32; ++i ) {
                if ( n & 1 ) {
                    ++bits[i];
                }
                n >>= 1;
            }
        }
        int n = nums.size(), h = 0;
        for ( int cnt : bits ) {
            h += cnt * (n - cnt);
        }
        return h;
    }
};
