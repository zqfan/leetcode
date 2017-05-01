class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0, count;
        for ( int i = 0; i < 32; ++i ) {
            count = 0;
            for ( int n : nums ) {
                if ( n & (1 << i) ) {
                    ++count;
                }
            }
            if ( count % 3 ) {
                single |= 1 << i;
            }
        }
        return single;
    }
};
