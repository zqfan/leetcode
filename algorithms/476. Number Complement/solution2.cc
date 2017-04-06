class Solution {
public:
    int findComplement(int num) {
        int i = 32;
        while ( 0 == ((1 << --i) & num) );
        return ((1 << (i+1))- 1) & (~num);
    }
};
