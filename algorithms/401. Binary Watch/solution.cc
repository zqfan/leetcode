class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        char t[6];
        for ( int h = 0; h < 12; ++h ) {
            for ( int m = 0; m < 60; ++m ) {
                if (bitset<4> (h).count() + bitset<6> (m).count() == num) {
                    sprintf(t, "%d:%02d", h, m);
                    result.push_back(t);
                }
            }
        }
        return result;
    }
};

// 10 / 10 test cases passed.
// Status: Accepted
// Runtime: 0 ms
