class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zero = 1;
        for ( int slot : flowerbed ) {
            if ( 0 == slot ) {
                ++zero;
            } else {
                n -= zero ? (zero - 1) / 2 : 0;
                zero = 0;
            }
        }
        n -= zero / 2;
        return n <= 0;
    }
};
