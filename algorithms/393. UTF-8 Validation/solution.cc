class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int follow = 0;
        for ( int n : data ) {
            if ( follow ) {
                if ( n >> 6 != 0b10 ) {
                    return false;
                }
                --follow;
            } else {
                if ( n >> 5 == 0b110 ) {
                    follow = 1;
                } else if ( n >> 4 == 0b1110 ) {
                    follow = 2;
                } else if ( n >> 3 == 0b11110 ) {
                    follow = 3;
                } else if ( n >> 7 ) {
                    return false;
                }
            }
        }
        return follow == 0;
    }
};
