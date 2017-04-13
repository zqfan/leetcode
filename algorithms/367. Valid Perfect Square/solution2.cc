class Solution {
public:
    bool isPerfectSquare(int num) {
        if ( num < 1 ) {
            return false;
        }
        for ( int i = 1; num > 0; i += 2 ) {
            num -= i;
        }
        return num == 0;
    }
};
