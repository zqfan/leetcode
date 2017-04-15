class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x, mid;
        while ( low <= high ) {
            mid = low + (high - low) / 2;
            if ( mid < x / mid ) {
                low = mid + 1;
            } else if ( mid > x / mid ) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low - 1;
    }
};
