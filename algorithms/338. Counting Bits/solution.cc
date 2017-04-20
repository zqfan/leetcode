class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> count(num + 1);
        for ( int i = 0; i <= num; ++i ) {
            count[i] = count[i >> 1] + (i & 1);
        }
        return count;
    }
};
