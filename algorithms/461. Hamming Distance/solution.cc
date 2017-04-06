class Solution {
public:
    int hammingDistance(int x, int y) {
        // @pengr7
        int z = x ^ y;
        int d = 0;
        while ( z ) {
            d++;
            z &= z - 1;
        }
        return d;
    }
};
