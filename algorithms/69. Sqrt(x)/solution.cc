class Solution {
public:
    int mySqrt(int x) {
        // based on @yuyibestman
        int root = 0;
        int bit = 1 << 16;
        while ( bit ) {
            root |= bit;
            if ( root > x / root ) {
                root ^= bit;
            }
            bit >>= 1;
        }
        return root;
    }
};
