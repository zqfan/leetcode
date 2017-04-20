class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for ( int n : nums ) {
            x ^= n;
        }
        // get last set bit, which is a diff bit for n1 and n2
        x &= -x;
        vector<int> single(2);
        for ( int n : nums ) {
            if ( n & x ) {
                single[0] ^= n;
            } else {
                single[1] ^= n;
            }
        }
        return single;
    }
};
