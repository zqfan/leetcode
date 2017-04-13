// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, mid, g;
        while ( low <= high ) {
            mid = low + (high - low) / 2;
            g = guess(mid);
            if ( 1 == g ) {
                low = mid + 1;
            } else if ( -1 == g ) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
    }
};
