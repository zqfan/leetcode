class Solution {
public:
    int bitwiseComplement(int N) {
        int x = 1;
        while ( N > x ) {
            x = (x << 1) + 1;
        }
        return x - N;
    }
};
