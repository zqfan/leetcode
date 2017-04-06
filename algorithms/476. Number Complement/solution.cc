class Solution {
public:
    int findComplement(int num) {
        int m = -1;
        while ( m & num ) {
            m <<= 1;
        }
        return (~m) ^ num;
    }
};
